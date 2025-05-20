//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum number of rules
#define MAX_RULES 10

// Define the structure of a rule
typedef struct rule {
  char *pattern;
  int score;
} rule;

// Define the structure of a message
typedef struct message {
  char *text;
  int score;
} message;

// Define the configuration file path
#define CONFIG_FILE "config.txt"

// Load the rules from the configuration file
rule *load_rules(char *config_file) {
  // Open the configuration file
  FILE *fp = fopen(config_file, "r");
  if (fp == NULL) {
    perror("Error opening configuration file");
    exit(EXIT_FAILURE);
  }

  // Read the number of rules
  int num_rules;
  fscanf(fp, "%d", &num_rules);

  // Allocate memory for the rules
  rule *rules = malloc(sizeof(rule) * num_rules);

  // Read each rule
  for (int i = 0; i < num_rules; i++) {
    // Read the pattern
    char *pattern = malloc(256);
    fscanf(fp, "%s", pattern);

    // Read the score
    int score;
    fscanf(fp, "%d", &score);

    // Store the rule
    rules[i].pattern = pattern;
    rules[i].score = score;
  }

  // Close the configuration file
  fclose(fp);

  // Return the rules
  return rules;
}

// Free the rules
void free_rules(rule *rules, int num_rules) {
  // Free each rule
  for (int i = 0; i < num_rules; i++) {
    free(rules[i].pattern);
  }

  // Free the rules array
  free(rules);
}

// Check if a message matches a rule
int check_rule(rule *rule, message *message) {
  // Check if the message contains the pattern
  if (strstr(message->text, rule->pattern) != NULL) {
    // Return the rule's score
    return rule->score;
  }

  // Return 0 if the message does not contain the pattern
  return 0;
}

// Check if a message is spam
int check_spam(rule *rules, int num_rules, message *message) {
  // Initialize the message's score
  message->score = 0;

  // Check each rule
  for (int i = 0; i < num_rules; i++) {
    // Check if the message matches the rule
    int score = check_rule(&rules[i], message);

    // Add the rule's score to the message's score
    message->score += score;
  }

  // Return 1 if the message's score is greater than 0, otherwise return 0
  return message->score > 0;
}

// Print the results
void print_results(message *message) {
  // Print the message's text
  printf("Message: %s\n", message->text);

  // Print the message's score
  printf("Score: %d\n", message->score);

  // Print whether the message is spam
  if (message->score > 0) {
    printf("Spam: Yes\n");
  } else {
    printf("Spam: No\n");
  }
}

// Main function
int main(int argc, char **argv) {
  // Check if the configuration file was specified
  if (argc != 2) {
    printf("Usage: %s config_file\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Load the rules
  rule *rules = load_rules(argv[1]);

  // Get the message text
  char *message_text = malloc(256);
  printf("Enter the message text: ");
  scanf("%s", message_text);

  // Create the message
  message message = {message_text, 0};

  // Check if the message is spam
  int is_spam = check_spam(rules, MAX_RULES, &message);

  // Print the results
  print_results(&message);

  // Free the memory
  free_rules(rules, MAX_RULES);
  free(message_text);

  return EXIT_SUCCESS;
}