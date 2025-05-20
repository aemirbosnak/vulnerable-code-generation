//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_URL_LENGTH 1000
#define MAX_THREADS 5

// Global variables
int sanitized_urls_count = 0;
char **sanitized_urls;

// Mutex lock
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// URL sanitizer function
void *sanitize_url(void *url) {
  char *original_url = (char *) url;

  // Allocate memory for a copy of the original URL
  char *clean_url = malloc(MAX_URL_LENGTH * sizeof(char));
  if (clean_url == NULL) {
    perror("Error allocating memory for clean URL");
    pthread_exit(NULL);
  }

  // Loop through each character in the original URL
  int j = 0;
  for (int i = 0; i < strlen(original_url); i++) {
    // Only add valid characters to the clean URL
    if ((original_url[i] >= 'a' && original_url[i] <= 'z') ||
        (original_url[i] >= 'A' && original_url[i] <= 'Z') ||
        (original_url[i] >= '0' && original_url[i] <= '9') ||
        (original_url[i] == '/') ||
        (original_url[i] == '.') ||
        (original_url[i] == ':')) {
      clean_url[j++] = original_url[i];
    }
  }
  clean_url[j] = '\0';

  // Lock the mutex before adding the sanitized URL to the global array
  pthread_mutex_lock(&lock);
  sanitized_urls[sanitized_urls_count++] = clean_url;
  pthread_mutex_unlock(&lock);

  pthread_exit(NULL);
}

int main() {
  // Allocate memory for global array of sanitized URLs
  sanitized_urls = malloc(MAX_URL_LENGTH * sizeof(char *));
  if (sanitized_urls == NULL) {
    perror("Error allocating memory for sanitized URLs");
    exit(EXIT_FAILURE);
  }

  // Array of original URLs
  char *original_urls[] = {"http://www.example.com", "https://www.example.com/login/", "ftp://ftp.example.com/downloads/file.txt", "http://www.website.com/about"};

  // Array of thread IDs
  pthread_t threads[MAX_THREADS];

  // Start each thread to sanitize one URL
  for (int i = 0; i < MAX_THREADS; i++) {
    if (pthread_create(&threads[i], NULL, sanitize_url, original_urls[i]) != 0) {
      perror("Error creating thread");
      exit(EXIT_FAILURE);
    }
  }

  // Wait for all threads to finish
  for (int i = 0; i < MAX_THREADS; i++) {
    if (pthread_join(threads[i], NULL) != 0) {
      perror("Error joining thread");
      exit(EXIT_FAILURE);
    }
  }

  // Print the sanitized URLs
  printf("Sanitized URLs:\n");
  for (int i = 0; i < sanitized_urls_count; i++) {
    printf("%s\n", sanitized_urls[i]);
    free(sanitized_urls[i]);
  }
  free(sanitized_urls);

  return 0;
}