//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  time_t start_time, end_time;
  float speed, total_time, downloaded_size = 50.0;
  char choice;

  printf("Welcome to the Internet Speed Test Application\n");
  printf("----------------------------------------------\n\n");
  printf("Please select a server to test your internet speed:\n");
  printf("1. Server A\n");
  printf("2. Server B\n");
  printf("3. Server C\n");

  scanf("%c", &choice);

  switch(choice)
  {
    case '1':
      printf("\nTesting Server A...\n");
      start_time = time(NULL);
      printf("Downloading %.1f MB file...\n", downloaded_size);
      // Simulating download by sleeping for 5 seconds
      sleep(5);
      end_time = time(NULL);
      break;

    case '2':
      printf("\nTesting Server B...\n");
      start_time = time(NULL);
      printf("Downloading %.1f MB file...\n", downloaded_size);
      // Simulating download by sleeping for 10 seconds
      sleep(10);
      end_time = time(NULL);
      break;

    case '3':
      printf("\nTesting Server C...\n");
      start_time = time(NULL);
      printf("Downloading %.1f MB file...\n", downloaded_size);
      // Simulating download by sleeping for 15 seconds
      sleep(15);
      end_time = time(NULL);
      break;

    default:
      printf("\nInvalid choice\n");
      return 0;
  }

  total_time = difftime(end_time, start_time);
  speed = downloaded_size / total_time;

  printf("\nDownload speed: %.2f MB/s\n", speed);

  return 0;
}