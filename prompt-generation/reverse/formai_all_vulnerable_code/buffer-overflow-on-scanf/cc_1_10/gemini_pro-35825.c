//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    char *name;
    Date birthDate;
    int luckyNumber;
} Person;

int main()
{
    Person person;

    printf("Enter your name: ");
    scanf("%s", person.name);

    printf("Enter your birth date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &person.birthDate.day, &person.birthDate.month, &person.birthDate.year);

    printf("Enter your lucky number: ");
    scanf("%d", &person.luckyNumber);

    // Calculate the person's age
    time_t now = time(NULL);
    struct tm *nowTm = localtime(&now);
    int age = nowTm->tm_year - person.birthDate.year;
    if (nowTm->tm_mon < person.birthDate.month || (nowTm->tm_mon == person.birthDate.month && nowTm->tm_mday < person.birthDate.day))
    {
        age--;
    }

    // Generate a random fortune
    srand(time(NULL));
    int fortuneIndex = rand() % 10;
    char *fortunes[] =
    {
        "You will have a long and prosperous life.",
        "You will find true love in a distant land.",
        "You will achieve great success in your career.",
        "You will travel the world and experience many different cultures.",
        "You will make a difference in the world.",
        "You will be happy and content with your life.",
        "You will overcome all obstacles and achieve your goals.",
        "You will find your purpose in life.",
        "You will live a long and healthy life.",
        "You will be surrounded by love and happiness."
    };

    // Print the fortune
    printf("Your fortune is: %s\n", fortunes[fortuneIndex]);

    return 0;
}