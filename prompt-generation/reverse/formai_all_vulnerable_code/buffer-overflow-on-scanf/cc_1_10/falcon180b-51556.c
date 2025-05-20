//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void meow(int num);
void purr(int num);
void hiss(int num);

int main() {
    int choice;

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please enter your choice:\n");
    printf("1. Meow\n");
    printf("2. Purr\n");
    printf("3. Hiss\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            meow(5);
            break;
        case 2:
            purr(7);
            break;
        case 3:
            hiss(3);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}

// Function definitions
void meow(int num) {
    for (int i = 0; i < num; i++) {
        printf("meow ");
    }
}

void purr(int num) {
    for (int i = 0; i < num; i++) {
        printf("purr ");
    }
}

void hiss(int num) {
    for (int i = 0; i < num; i++) {
        printf("hiss ");
    }
}