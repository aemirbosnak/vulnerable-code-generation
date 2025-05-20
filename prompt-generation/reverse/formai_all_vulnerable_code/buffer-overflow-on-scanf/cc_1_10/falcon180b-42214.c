//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char name[20];
    int age;
    int gender;
    int health = 100;
    int money = 100;
    char *greetings[3] = {"Hello", "Hi", "Hey"};
    char *farewells[3] = {"Goodbye", "Bye", "See you later"};

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    srand(time(NULL));
    gender = rand() % 2;

    if (gender == 0) {
        printf("You are a %s.\n", "man");
    } else {
        printf("You are a %s.\n", "woman");
    }

    printf("You are %d years old.\n", age = rand() % 101);

    while (health > 0) {
        printf("\nYou have %d health points and $%d.\n", health, money);
        printf("What would you like to do?\n");
        printf("1. Go to the market\n");
        printf("2. Go to the gym\n");
        printf("3. Go to the hospital\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You went to the market and spent $%d.\n", money -= rand() % 51 + 50);
                break;
            case 2:
                printf("You went to the gym and increased your health by %d points.\n", health += rand() % 11 + 10);
                break;
            case 3:
                printf("You went to the hospital and spent $%d.\n", money -= rand() % 101 + 100);
                break;
            case 4:
                printf("%s, %s! See you next time!\n", farewells[rand() % 3], name);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}