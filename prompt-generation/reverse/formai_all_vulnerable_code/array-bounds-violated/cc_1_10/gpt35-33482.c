//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENT_SIZE 100

int main(int argc, char *argv[]) {

   char event[MAX_EVENT_SIZE];
   char *detection_regex = "^([a-zA-Z]+){4,}"; // regex rule for detection

   while (1) {
      printf("Enter event: ");
      fflush(stdout);

      if (fgets(event, MAX_EVENT_SIZE, stdin) == NULL) {
         fprintf(stderr, "Error reading input!\n");
         return EXIT_FAILURE;
      }

      if (event[strlen(event) - 1] == '\n') {
         event[strlen(event) - 1] = '\0'; // remove newline character
      }

      if (strstr(event, "exit") != NULL) {
         printf("Exiting...\n");
         break;
      }

      if (strstr(event, "detect ") != NULL) {
         detection_regex = strstr(event, "detect ") + 7; // extract regex from input
         printf("Detection regex updated.\n");
         continue;
      }

      if (strlen(event) < 4) {
         printf("Invalid event length.\n");
         continue;
      }

      if (strstr(event, " ") == NULL) {
         printf("Invalid event format.\n");
         continue;
      }

      if (regexec(detection_regex, event, 0, NULL, 0) == 0) {
         printf("Intrusion detected: %s\n", event);
      }
      else {
         printf("Event accepted: %s\n", event);
      }
   }

   return EXIT_SUCCESS;
}