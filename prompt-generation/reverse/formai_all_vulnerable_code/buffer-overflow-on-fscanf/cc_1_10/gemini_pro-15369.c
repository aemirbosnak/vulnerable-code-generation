//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the data structure for a transaction
typedef struct {
  int id;
  char items[100];
} Transaction;

// Define the data structure for a rule
typedef struct {
  char antecedent[100];
  char consequent[100];
  double confidence;
} Rule;

// Read the transactions from a file
int read_transactions(char *filename, Transaction *transactions) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return -1;
  }

  int num_transactions = 0;
  while (fscanf(fp, "%d %s", &transactions[num_transactions].id, transactions[num_transactions].items) != EOF) {
    num_transactions++;
  }

  fclose(fp);

  return num_transactions;
}

// Generate all possible rules from the transactions
int generate_rules(Transaction *transactions, int num_transactions, Rule *rules) {
  int num_rules = 0;

  // For each transaction
  for (int i = 0; i < num_transactions; i++) {
    // For each item in the transaction
    char *item = strtok(transactions[i].items, " ");
    while (item != NULL) {
      // For each other item in the transaction
      char *other_item = strtok(NULL, " ");
      while (other_item != NULL) {
        // If the two items are different
        if (strcmp(item, other_item) != 0) {
          // Create a new rule
          strcpy(rules[num_rules].antecedent, item);
          strcpy(rules[num_rules].consequent, other_item);

          // Calculate the confidence of the rule
          int num_antecedent = 0;
          int num_antecedent_and_consequent = 0;
          for (int j = 0; j < num_transactions; j++) {
            if (strstr(transactions[j].items, rules[num_rules].antecedent) != NULL) {
              num_antecedent++;
              if (strstr(transactions[j].items, rules[num_rules].consequent) != NULL) {
                num_antecedent_and_consequent++;
              }
            }
          }
          rules[num_rules].confidence = (double)num_antecedent_and_consequent / num_antecedent;

          // Increment the number of rules
          num_rules++;
        }

        // Get the next item in the transaction
        other_item = strtok(NULL, " ");
      }

      // Get the next item in the transaction
      item = strtok(NULL, " ");
    }
  }

  return num_rules;
}

// Print the rules to a file
void print_rules(char *filename, Rule *rules, int num_rules) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }

  // Print each rule to the file
  for (int i = 0; i < num_rules; i++) {
    fprintf(fp, "%s -> %s (%.2f%%)\n", rules[i].antecedent, rules[i].consequent, rules[i].confidence * 100);
  }

  fclose(fp);
}

// Main function
int main() {
  // Read the transactions from a file
  Transaction transactions[1000];
  int num_transactions = read_transactions("transactions.txt", transactions);

  // Generate all possible rules from the transactions
  Rule rules[10000];
  int num_rules = generate_rules(transactions, num_transactions, rules);

  // Print the rules to a file
  print_rules("rules.txt", rules, num_rules);

  return 0;
}