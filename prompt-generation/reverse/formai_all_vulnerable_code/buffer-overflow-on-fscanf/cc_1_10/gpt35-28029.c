//FormAI DATASET v1.0 Category: Log analysis ; Style: romantic
#include <stdio.h>

int main() {
  // Let's analyze our love log
  printf("My dear love, let us analyze our log,\n");
  printf("To see if our relationship is truly agog.\n");
  
  // Reading the log file
  FILE *fp = fopen("love_log.txt", "r");
  if (fp == NULL) {
    printf("Error opening the log file!\n");
    return 1;
  } else {
    printf("Opening the log file, my heart starts to soar,\n");
  }
  
  // Variables to keep track of log entries
  int date, time;
  float happiness;
  
  // Analyzing each log entry
  int total_entries = 0, happy_entries = 0;
  while (fscanf(fp, "%d %d %f", &date, &time, &happiness) == 3) {
    total_entries++;
    if (happiness >= 7.0) {
      happy_entries++;
    }
  }
  
  // Closing the log file
  fclose(fp);
  printf("Closing the log file, my love with you I'll adore.\n");
  
  // Displaying the results
  float love_percentage = (float) happy_entries / total_entries * 100;
  printf("Our love percentage is %.2f percent,\n", love_percentage);
  
  if (love_percentage >= 90) {
    printf("Our love is going strong, I feel so content.\n");
  } else if (love_percentage >= 70) {
    printf("Our love is blossoming, each day is heaven sent.\n");
  } else if (love_percentage >= 50) {
    printf("Our love is like a ship, steady and afloat.\n");
  } else if (love_percentage >= 30) {
    printf("Our love needs work, but together we'll stay afloat.\n");
  } else {
    printf("Our love is in danger, we need to talk and take note.\n");
  }
  
  // Returning with a smile
  printf("My dear love, our log analysis is now done,\n");
  printf("But our journey together has only just begun.\n");
  return 0;
}