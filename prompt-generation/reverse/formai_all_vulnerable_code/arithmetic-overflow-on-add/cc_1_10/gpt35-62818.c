//FormAI DATASET v1.0 Category: Weather simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 5
#define MAX_TEMPERATURE 35
#define MIN_TEMPERATURE 15
#define MAX_HUMIDITY 100
#define MIN_HUMIDITY 0

int temperature = 20; // Starting temperature
int humidity = 50; // Starting humidity
pthread_mutex_t t_lock; // Temperature mutex lock
pthread_mutex_t h_lock; // Humidity mutex lock

void* weather(void* threadid) {
  long tid;
  tid = (long)threadid;
  printf("Thread %ld starting...\n", tid);
  srand(time(NULL) + tid); // Set the seed for random number generation
  
  while (1) {
    int temp_change = rand() % 7 - 3; // Generate random number between -3 and 3
    int humidity_change = rand() % 11 - 5; // Generate random number between -5 and 5
    
    // Acquire mutex locks before updating temperature and humidity
    pthread_mutex_lock(&t_lock);
    pthread_mutex_lock(&h_lock);
    
    temperature += temp_change;
    humidity += humidity_change;
    
    // Keep temperature and humidity between minimum and maximum values
    if (temperature > MAX_TEMPERATURE) {
      temperature = MAX_TEMPERATURE;
    }
    else if (temperature < MIN_TEMPERATURE) {
      temperature = MIN_TEMPERATURE;
    }
    
    if (humidity > MAX_HUMIDITY) {
      humidity = MAX_HUMIDITY;
    }
    else if (humidity < MIN_HUMIDITY) {
      humidity = MIN_HUMIDITY;
    }
    
    printf("Thread %ld: Temperature = %d, Humidity = %d\n", tid, temperature, humidity);
    
    // Release mutex locks after updating temperature and humidity
    pthread_mutex_unlock(&t_lock);
    pthread_mutex_unlock(&h_lock);
    
    sleep(1); // Sleep for 1 second
  }
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  
  // Initialize mutex locks
  pthread_mutex_init(&t_lock, NULL);
  pthread_mutex_init(&h_lock, NULL);
  
  for (t = 0; t < NUM_THREADS; t++) {
    rc = pthread_create(&threads[t], NULL, weather, (void*)t);
    if (rc) {
      printf("ERROR: return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  
  pthread_exit(NULL);
  
  // Destroy mutex locks
  pthread_mutex_destroy(&t_lock);
  pthread_mutex_destroy(&h_lock);
}