//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

static const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.",
    "--.", "....", "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..",
    "----.", "-----", "/", ".-.-.-", "--..--"
};

static char output[MAX_STRING_LENGTH * 5];
static pthread_mutex_t output_mutex = PTHREAD_MUTEX_INITIALIZER;
static int next_output_position = 0;

void *morse_converter_thread(void *arg) {
  char *input = (char*) arg;
  int i, j;
  for (i = 0; i < strlen(input); ++i) {
    char c = input[i];
    if (c >= 'a' && c <= 'z') {
      c -= 'a';
    } else if (c >= 'A' && c <= 'Z') {
      c -= 'A';
    } else if (c >= '0' && c <= '9') {
      c = c - '0' + 26;
    } else if (c == ' ') {
      c = 36;
    } else if (c == '.') {
      c = 37;
    } else if (c == ',') {
      c = 38;
    }
    const char *morse = morse_table[c];
    pthread_mutex_lock(&output_mutex);
    for (j = 0; j < strlen(morse); ++j) {
      output[next_output_position++] = morse[j];
    }
    pthread_mutex_unlock(&output_mutex);
  }
  return NULL;
}

int main() {
  pthread_t thread;
  char input[MAX_STRING_LENGTH];
  
  printf("Enter text to convert to Morse code: ");
  fgets(input, MAX_STRING_LENGTH, stdin);
  input[strlen(input)-1] = '\0'; // remove newline
  
  pthread_create(&thread, NULL, morse_converter_thread, input);
  
  pthread_join(thread, NULL);
  
  pthread_mutex_lock(&output_mutex);
  output[next_output_position] = '\0';
  printf("%s\n", output);
  pthread_mutex_unlock(&output_mutex);
  
  pthread_mutex_destroy(&output_mutex);
  return 0;
}