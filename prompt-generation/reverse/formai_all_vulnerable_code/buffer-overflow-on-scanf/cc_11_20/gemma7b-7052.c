//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ANSWERS 5

typedef struct {
    char name[20];
    int age;
    char sign[20];
} Person;

int main() {
    srand(time(NULL));
    Person person;
    printf("Enter your name: ");
    scanf("%s", person.name);
    printf("Enter your age: ");
    scanf("%d", &person.age);

    // Calculate person's sign based on their birthdate
    int month = person.age / 12;
    switch (month) {
        case 0:
            strcpy(person.sign, "Capricorn");
            break;
        case 1:
            strcpy(person.sign, "Aquarius");
            break;
        case 2:
            strcpy(person.sign, "Pisces");
            break;
        case 3:
            strcpy(person.sign, "Aries");
            break;
        case 4:
            strcpy(person.sign, "Taurus");
            break;
        case 5:
            strcpy(person.sign, "Gemini");
            break;
        case 6:
            strcpy(person.sign, "Cancer");
            break;
        case 7:
            strcpy(person.sign, "Leo");
            break;
        case 8:
            strcpy(person.sign, "Virgo");
            break;
        case 9:
            strcpy(person.sign, "Libra");
            break;
        case 10:
            strcpy(person.sign, "Scorpio");
            break;
        case 11:
            strcpy(person.sign, "Sagittarius");
            break;
        case 12:
            strcpy(person.sign, "Capricorn");
            break;
    }

    // Generate a random answer
    int answer_index = rand() % MAX_ANSWERS;
    char answers[MAX_ANSWERS][20] = {
        "You will find great success in your chosen field.",
        "You will experience a period of happiness and contentment.",
        "Your relationships will be strong and fulfilling.",
        "You may face some challenges, but you will overcome them.",
        "Your intuition will be strong, and you will make wise decisions."
    };

    // Display the fortune
    printf("Your fortune is: %s", answers[answer_index]);

    return 0;
}