//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ANSWERS 5

typedef struct {
    char name[20];
    int age;
    char sign[20];
    int lucky_number;
} Person;

int main() {
    srand(time(NULL));

    // Create an array of people
    Person people[MAX_ANSWERS] = {
        {"Alice", 25, "Aries", 3},
        {"Bob", 30, "Taurus", 5},
        {"Charlie", 20, "Gemini", 7},
        {"Diana", 40, "Virgo", 11},
        {"Ethan", 35, "Libra", 9}
    };

    // Get the user's name and age
    char user_name[20];
    int user_age;
    printf("What is your name? ");
    scanf("%s", user_name);

    printf("How old are you? ");
    scanf("%d", &user_age);

    // Find the user's horoscope sign
    char user_sign[20];
    int user_lucky_number;
    for (int i = 0; i < MAX_ANSWERS; i++) {
        if (strcmp(people[i].name, user_name) == 0) {
            strcpy(user_sign, people[i].sign);
            user_lucky_number = people[i].lucky_number;
        }
    }

    // Print the user's horoscope reading
    printf("Your horoscope sign is: %s\n", user_sign);

    printf("Your lucky number is: %d\n", user_lucky_number);

    return 0;
}