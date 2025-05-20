//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: romantic
#include <stdio.h>
#include <string.h>

#define LOVE 100
#define HEART 32

void print_love(int amount) {
    int i, j;
    char heart = HEART;

    for (i = 0; i < amount; i++) {
        for (j = 0; j < amount; j++) {
            printf("%c ", heart);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    printf("Welcome to my heart, my love! \n");
    printf("Please choose your desired amount of love:\n");
    printf("1. A single heartbeat\n");
    printf("2. A love letter\n");
    printf("3. A romantic dinner for two\n");
    printf("4. A forever love\n");

    scanf("%d", &choice);

    switch (choice) {
    case 1:
        print_love(LOVE);
        break;
    case 2:
        print_love(HEART);
        break;
    case 3:
        print_love(32);
        break;
    case 4:
        print_love(100);
        break;
    default:
        printf("Invalid choice, my love. Please try again.\n");
        break;
    }

    return 0;
}