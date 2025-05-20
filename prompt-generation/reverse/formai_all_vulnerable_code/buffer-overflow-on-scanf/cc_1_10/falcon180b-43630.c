//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MESSAGES 100

typedef struct {
    char *message;
    int length;
} message_t;

message_t messages[MAX_MESSAGES];
int num_messages;

void add_message(char *str) {
    if (num_messages >= MAX_MESSAGES) {
        printf("Error: Maximum number of messages reached.\n");
        return;
    }

    messages[num_messages].message = strdup(str);
    messages[num_messages].length = strlen(str);

    num_messages++;
}

void shuffle_messages() {
    for (int i = 0; i < num_messages; i++) {
        int j = rand() % num_messages;
        message_t temp = messages[i];
        messages[i] = messages[j];
        messages[j] = temp;
    }
}

void print_message(int index) {
    if (index >= num_messages) {
        printf("Error: Invalid message index.\n");
        return;
    }

    printf("%s\n", messages[index].message);
}

int main() {
    srand(time(NULL));

    add_message("You will have good luck today.");
    add_message("A new opportunity will present itself to you.");
    add_message("You will find love in unexpected places.");
    add_message("Your hard work will pay off soon.");
    add_message("A friend will need your help.");

    shuffle_messages();

    int choice;
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Enter 1 to get a fortune or 0 to exit:\n");

    scanf("%d", &choice);

    while (choice!= 0) {
        int index = rand() % num_messages;
        print_message(index);

        printf("Enter 1 to get another fortune or 0 to exit:\n");
        scanf("%d", &choice);
    }

    return 0;
}