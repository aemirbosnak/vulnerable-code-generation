//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOVE 1
#define HEART 2
#define KISS 3

int main() {
    int choice;
    char name[20];
    char message[100];

    printf("Welcome to the Romantic Adventure!\n");

    do {
        printf("Choose your next step:\n");
        printf("1. Declare your love\n");
        printf("2. Give a heart\n");
        printf("3. Steal a kiss\n");

        scanf("%d", &choice);

        switch (choice) {
            case LOVE:
                printf("Who is the lucky one you love? ");
                fgets(name, 20, stdin);
                printf("You declare your love for %s!\n", name);
                break;

            case HEART:
                printf("You give a heart to %s, they blush with delight! \n", name);
                break;

            case KISS:
                printf("You steal a kiss from %s, the sparks fly! \n", name);
                break;
        }
    } while (1);

    return 0;
}

void declare_love(char *name) {
    printf("You declare your love for %s, your heart beats faster! \n", name);
}

void give_heart(char *name) {
    printf("You give a heart to %s, they smile with joy! \n", name);
}

void steal_kiss(char *name) {
    printf("You steal a kiss from %s, the magic of love is in the air! \n", name);
}