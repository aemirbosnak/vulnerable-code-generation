//FormAI DATASET v1.0 Category: Unit converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <signal.h>

#define BUFSZ 1024

static volatile bool running = true;

// Function to check if input is a valid double
bool is_number(char* input) {
   for (int i = 0; i < strlen(input); i++) {
      if (i == 0 && (input[i] == '-' || input[i] == '+')) {
         continue;
      }
      if (!isdigit(input[i]) && input[i] != '.') {
         return false;
      }
   }
   return true;
}

// Function to convert Celsius to Fahrenheit
double c_to_f(double celsius) {
   return ((celsius * 9) / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
double f_to_c(double fahrenheit) {
   return ((fahrenheit - 32) * 5) / 9;
}

// Signal handler to gracefully exit program on CTRL-C
void sig_handler(int sig) {
   printf("\n");
   running = false;
}

int main(int argc, char* argv[]) {
   if (argc != 3) {
      fprintf(stderr, "Usage: %s <input_unit> <output_unit>\n", argv[0]);
      return EXIT_FAILURE;
   }

   char* input_unit = argv[1];
   char* output_unit = argv[2];

   if (strcasecmp(input_unit, "C") != 0 && strcasecmp(input_unit, "F") != 0) {
      fprintf(stderr, "Invalid input unit '%s'\n", input_unit);
      return EXIT_FAILURE;
   }

   if (strcasecmp(output_unit, "C") != 0 && strcasecmp(output_unit, "F") != 0) {
      fprintf(stderr, "Invalid output unit '%s'\n", output_unit);
      return EXIT_FAILURE;
   }

   struct sigaction action;
   memset(&action, 0, sizeof(struct sigaction));
   action.sa_handler = sig_handler;
   sigaction(SIGINT, &action, NULL);

   char buffer[BUFSZ];
   while (running) {
      printf("Enter temperature in %s: ", input_unit);
      fflush(stdout);
      if (!fgets(buffer, BUFSZ, stdin)) {
         if (errno == EINTR) {
            continue;
         }
         perror("fgets");
         return EXIT_FAILURE;
      }
      buffer[strcspn(buffer, "\n")] = '\0';

      if (is_number(buffer)) {
         double input_temp = strtod(buffer, NULL);
         double output_temp = 0;

         if (strcasecmp(input_unit, "C") == 0 && strcasecmp(output_unit, "F") == 0) {
            output_temp = c_to_f(input_temp);
         } else if (strcasecmp(input_unit, "F") == 0 && strcasecmp(output_unit, "C") == 0) {
            output_temp = f_to_c(input_temp);
         } else {
            printf("Invalid unit combination: %s to %s\n", input_unit, output_unit);
            continue;
         }

         printf("%g %s = %g %s\n", input_temp, input_unit, output_temp, output_unit);
      } else {
         printf("Invalid input: '%s' is not a valid number\n", buffer);
      }
   }

   return EXIT_SUCCESS;
}