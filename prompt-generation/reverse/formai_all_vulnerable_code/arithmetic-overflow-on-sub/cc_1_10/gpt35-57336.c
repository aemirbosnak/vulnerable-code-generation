//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CONFIG_FILE "config.txt"
#define MAX_LINE_LENGTH 100
#define MAX_CONFIG_LINES 5

char *fortune_list[] = {
    "Good things come to those who wait",
    "Everything happens for a reason",
    "The best is yet to come",
    "Your future is looking bright",
    "You will find success in the near future",
    "A new opportunity will arise soon",
    "Happiness is just around the corner",
    "Your hard work will pay off",
    "You are on the right path to success",
    "Keep pushing forward, good things are coming"
};

int main() {
   FILE *config_file;
   char line[MAX_LINE_LENGTH];
   int number_of_fortunes = sizeof(fortune_list) / sizeof(fortune_list[0]);
   int fortune_index;
   char fortune_message[MAX_LINE_LENGTH];
   time_t t;

   srand((unsigned) time(&t));

   // Open configuration file
   config_file = fopen(CONFIG_FILE, "r");

   if (config_file == NULL) {
      printf("Error: Unable to open configuration file %s\n", CONFIG_FILE);
      return 1;
   }

   // Read each line of the configuration file and parse the integer values
   char *config_lines[MAX_CONFIG_LINES];
   int config_line_count = 0;
   while(fgets(line, MAX_LINE_LENGTH, config_file) != NULL && config_line_count < MAX_CONFIG_LINES) {
      config_lines[config_line_count++] = line;
   }

   // Convert configuration values to integers
   int min_wait_time = atoi(config_lines[0]);
   int max_wait_time = atoi(config_lines[1]);
   int number_of_messages = atoi(config_lines[2]);
   int message_delay_time = atoi(config_lines[3]);
   int exit_after_time = atoi(config_lines[4]);

   // Close configuration file
   fclose(config_file);

   // Begin fortune telling loop
   time_t start_time = time(NULL);
   while(1) {
       fortune_index = rand() % number_of_fortunes;
       printf("\nFortune Teller says: %s\n", fortune_list[fortune_index]);

       if (--number_of_messages == 0) {
           printf("\nEnd of session\n");
           break;
       }

       // Calculate the random wait time
       int wait_time = rand() % (max_wait_time - min_wait_time + 1) + min_wait_time;
       printf("Waiting %d seconds until next message\n", wait_time);
       sleep(wait_time);

       // Calculate the message delay time
       printf("Pausing for %d seconds before next message\n", message_delay_time);
       sleep(message_delay_time);

       // Exit after set amount of time has elapsed
       if (time(NULL) - start_time >= exit_after_time) {
           printf("\nEnd of session\n");
           break;
       }
   }

   return 0;
}