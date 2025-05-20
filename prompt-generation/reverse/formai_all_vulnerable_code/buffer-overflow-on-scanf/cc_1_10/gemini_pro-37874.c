//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Scavenge supplies for password analysis
int scavengeSupplies(char *password) {
  int supplies = 0;

  // Search for scavengable characters
  for (int i = 0; i < strlen(password); i++) {
    if (password[i] >= 'a' && password[i] <= 'z') supplies += 1;
    else if (password[i] >= 'A' && password[i] <= 'Z') supplies += 2;
    else if (password[i] >= '0' && password[i] <= '9') supplies += 3;
    else supplies += 5;
  }

  return supplies;
}

// Assess password strength based on scavenged supplies
int assessPassword(int supplies) {
  int strength;

  // Determine strength based on supplies
  if (supplies <= 20) strength = 1;
  else if (supplies <= 40) strength = 2;
  else if (supplies <= 60) strength = 3;
  else if (supplies <= 80) strength = 4;
  else strength = 5;

  return strength;
}

int main() {
  char password[100];

  // Welcome survivor!
  printf("Greetings, survivor! Let's check the strength of your password.\n");

  // Request password
  printf("Enter your password: ");
  scanf("%s", password);

  // Scavenge supplies
  int supplies = scavengeSupplies(password);

  // Assess password strength
  int strength = assessPassword(supplies);

  // Report results
  printf("Password strength: %d\n", strength);

  // Provide tips
  if (strength == 1) printf("Your password is weak! Consider adding more characters and symbols.\n");
  else if (strength == 2) printf("Your password is fair. Adding more complexity would improve its strength.\n");
  else if (strength == 3) printf("Your password is good. Keep it secret and don't share it with anyone.\n");
  else if (strength == 4) printf("Your password is strong. You're well-prepared for the dangers ahead.\n");
  else printf("Your password is exceptional! You're a master of survival.\n");

  return 0;
}