//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 10
#define MAX_NAME_LEN 50

typedef struct Medicine {
    char name[MAX_NAME_LEN];
    int quantity;
} Medicine;

Medicine store[MAX_MEDICINES];
int num_medicines = 0;

void add_medicine(char* name, int quantity) {
    if (num_medicines >= MAX_MEDICINES) {
        printf("Store is full. Cannot add medicine.\n");
        return;
    }
    strcpy(store[num_medicines].name, name);
    store[num_medicines].quantity = quantity;
    num_medicines++;
}

void remove_medicine(char* name) {
    int i;
    for (i = 0; i < num_medicines; i++) {
        if (strcmp(store[i].name, name) == 0) {
            int j;
            for (j = i; j < num_medicines - 1; j++) {
                store[j] = store[j + 1];
            }
            num_medicines--;
            printf("Medicine %s removed.\n", name);
            return;
        }
    }
    printf("Medicine %s not found.\n", name);
}

void view_medicines() {
    int i;
    for (i = 0; i < num_medicines; i++) {
        printf("%s: %d\n", store[i].name, store[i].quantity);
    }
}

int main() {
    char command[5];
    char name[MAX_NAME_LEN];
    int quantity, i;

    while (1) {
        printf("\nMedical Store Management System\n");
        printf("Enter command (add/remove/view/quit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        if (strcmp(command, "add") == 0) {
            printf("Enter medicine name: ");
            scanf("%s", name);
            printf("Enter medicine quantity: ");
            scanf("%d", &quantity);
            add_medicine(name, quantity);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter medicine name: ");
            scanf("%s", name);
            remove_medicine(name);
        } else if (strcmp(command, "view") == 0) {
            view_medicines();
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}