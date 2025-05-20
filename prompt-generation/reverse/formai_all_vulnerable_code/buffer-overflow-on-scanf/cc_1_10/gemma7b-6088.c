//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a structure to store a person's name, age, and fortune
    typedef struct Person
    {
        char name[20];
        int age;
        int fortune;
    } Person;

    // Create an array of 10 people
    Person people[10] =
    {
        {"John Doe", 25, 1000},
        {"Jane Doe", 30, 2000},
        {"Bob Smith", 40, 3000},
        {"Alice White", 50, 4000},
        {"Tom Jones", 60, 5000},
        {"Mary Johnson", 70, 6000},
        {"Peter Parker", 80, 7000},
        {"Clark Kent", 90, 8000},
        {"Superman", 100, 9000},
        {"Batman", 110, 10000}
    };

    // Get the person's name, age, and fortune
    char name[20];
    int age;
    int fortune;

    // Prompt the person to enter their name and age
    printf("What is your name? ");
    scanf("%s", name);

    printf("How old are you? ");
    scanf("%d", &age);

    // Find the person's fortune
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(name, people[i].name) == 0 && age == people[i].age)
        {
            fortune = people[i].fortune;
            break;
        }
    }

    // Print the person's fortune
    printf("Your fortune is $%d.", fortune);

    return 0;
}