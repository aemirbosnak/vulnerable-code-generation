//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define the vault dweller structure
typedef struct {
  char name[20];
  int strength;
  int perception;
  int endurance;
  int charisma;
  int intelligence;
  int agility;
  int luck;
} VaultDweller;

// Define the raider structure
typedef struct {
  char name[20];
  int strength;
  int perception;
  int endurance;
  int charisma;
  int intelligence;
  int agility;
  int luck;
} Raider;

// Define the search function
int search(VaultDweller* vaultDwellers, int numVaultDwellers, Raider* raiders, int numRaiders, char* name) {
  // Loop through the vault dwellers
  for (int i = 0; i < numVaultDwellers; i++) {
    // Check if the vault dweller's name matches the name we're searching for
    if (strcmp(vaultDwellers[i].name, name) == 0) {
      // Return the index of the vault dweller
      return i;
    }
  }

  // Loop through the raiders
  for (int i = 0; i < numRaiders; i++) {
    // Check if the raider's name matches the name we're searching for
    if (strcmp(raiders[i].name, name) == 0) {
      // Return the index of the raider
      return i;
    }
  }

  // Return -1 if the name was not found
  return -1;
}

// Main function
int main() {
  // Create an array of vault dwellers
  VaultDweller vaultDwellers[] = {
    {"John Smith", 5, 5, 5, 5, 5, 5, 5},
    {"Jane Doe", 5, 5, 5, 5, 5, 5, 5},
    {"Michael Jones", 5, 5, 5, 5, 5, 5, 5},
    {"Sarah Williams", 5, 5, 5, 5, 5, 5, 5}
  };

  // Create an array of raiders
  Raider raiders[] = {
    {"Butch", 5, 5, 5, 5, 5, 5, 5},
    {"Talon", 5, 5, 5, 5, 5, 5, 5},
    {"Murphy", 5, 5, 5, 5, 5, 5, 5},
    {"Clover", 5, 5, 5, 5, 5, 5, 5}
  };

  // Get the name of the person we're searching for
  char name[20];
  printf("Enter the name of the person you're searching for: ");
  scanf("%s", name);

  // Search for the person
  int index = search(vaultDwellers, 4, raiders, 4, name);

  // Print the results
  if (index == -1) {
    printf("The person you're searching for was not found.\n");
  } else {
    printf("The person you're searching for is: ");
    if (index < 4) {
      printf("%s (Vault Dweller)\n", vaultDwellers[index].name);
    } else {
      printf("%s (Raider)\n", raiders[index - 4].name);
    }
  }

  return 0;
}