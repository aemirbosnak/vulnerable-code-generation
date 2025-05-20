//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: puzzling
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _account {
  float balance;
  char name[256];
  struct _account *next;
} account;

int main() {
  account *head = NULL;
  char name[256];
  float amount;

  // Enchanting Prompt for Banking Operations
  while (1) {
    printf(
        "\nPerform your magical banking wizardry:\n"
        "  1. Create an Enchanted Account\n"
        "  2. Deposit the Moon's Shimmer\n"
        "  3. Withdraw a Star's Dust\n"
        "  4. Peek into the Ancient Vault\n"
        "  5. Exit the Enchanted Realm\n"
        "> ");

    int choice;
    scanf(" %d", &choice);

    switch (choice) {
      case 1:
        printf("Name of the Enchanted Account Holder: ");
        scanf(" %s", name);

        account *new_account = malloc(sizeof(account));
        new_account->balance = 0.0;
        strcpy(new_account->name, name);
        new_account->next = head;

        head = new_account;

        printf("May your account prosper in this realm!\n");
        break;

      case 2:
        printf("Name of the Enchanted Account Holder: ");
        scanf(" %s", name);

        account *depositor = head;
        while (depositor != NULL) {
          if (strcmp(depositor->name, name) == 0) {
            printf("Amount of Moon's Shimmer to deposit: ");
            scanf(" %f", &amount);

            depositor->balance += amount;
            printf("Your balance now glistens like a starry night!\n");
            break;
          }
          depositor = depositor->next;
        }

        if (depositor == NULL) {
          printf("No such Enchanted Account. Consult the Ancient Vault.\n");
        }
        break;

      case 3:
        printf("Name of the Enchanted Account Holder: ");
        scanf(" %s", name);

        account *withdrawer = head;
        while (withdrawer != NULL) {
          if (strcmp(withdrawer->name, name) == 0) {
            printf("Amount of Star's Dust to withdraw: ");
            scanf(" %f", &amount);

            if (withdrawer->balance >= amount) {
              withdrawer->balance -= amount;
              printf("Your balance now whispers secrets to the night.\n");
            } else {
              printf("Insufficient funds. Be patient, young one.\n");
            }
            break;
          }
          withdrawer = withdrawer->next;
        }

        if (withdrawer == NULL) {
          printf("No such Enchanted Account. Seek guidance from the Ancient Vault.\n");
        }
        break;

      case 4:
        printf("Behold the Ancient Vault of Enchanted Accounts:\n");
        account *explorer = head;

        while (explorer != NULL) {
          printf("  Name: %s\n  Balance: %.2f\n", explorer->name,
                 explorer->balance);
          explorer = explorer->next;
        }
        break;

      case 5:
        printf("May your banking endeavors be blessed. Farewell!\n");
        return 0;

      default:
        printf("Invalid choice. Consult the Cosmic Banker.\n");
    }
  }

  return 0;
}