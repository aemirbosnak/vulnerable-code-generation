//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: retro
// Throwback Thursday Spam Detection System

#include <stdio.h>
#include <string.h>

// Classic ASCII art banner
char *banner =
"    __  .__  .__                    __     ____   .___________.\n"
"   |  | |  | |  |                  |  |    \   \ /   _____/|  |\n"
"   |  | |  | |  |   ___________   |  |     \   Y   /  ___/ |  |_\n"
"   |  | |  | |  |  /  ___/  ___/  |  |      |    \ /   ___/  |____\n"
"   |__| |__| |__|  \___  >____   |__|      |     \\_____  >______|\n"
"                         \/     |__|      |__|         \/      \n\n";

// Signature Database (using old-school pointers)
char **signatures[] = {
  "FREE MONEY!", "URGENT!", "WIN A PRIZE!", "Meet Singles in Your Area!",
  "Enlarge Your...", "Lose Weight Fast!", "Get Rich Quick!", "Miracle Cure!",
  NULL // Terminator
};

// Classic Mainframe-style Function
int main(int argc, char **argv) {
  // Initialize variables
  char message[80]; // Generous buffer size for those long spam messages
  int found = 0; // Flag to indicate spam

  // Welcome message
  printf("%s\n", banner);
  printf("Welcome to the Spam Detection System 3000!\nReady to analyze incoming messages...\n\n");

  // Prompt for message
  printf("Enter message: ");
  gets(message);

  // Sequential search through signature database
  printf("\nRunning analysis...\n");
  for (int i = 0; signatures[i] != NULL; i++) {
    if (strstr(message, signatures[i]) != NULL) {
      found = 1;
      break;
    }
  }

  // Results
  printf("\nAnalysis complete.\n");
  if (found) {
    printf("Message contains spam! Proceed with caution.\n");
  } else {
    printf("Message appears to be legitimate.\n");
  }

  return 0;
}