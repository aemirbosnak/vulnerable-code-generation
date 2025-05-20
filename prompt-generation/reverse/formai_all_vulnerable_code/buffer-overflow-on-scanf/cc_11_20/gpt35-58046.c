//FormAI DATASET v1.0 Category: Data validation ; Style: happy
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char name[50];
    int age;
    float gpa;

    printf("Hello there! Let's get started with your information!\n");

    // validate name input
    do
    {
        printf("Please enter your full name: ");
        scanf("%[^\n]s", name);

        // check if name contains only letters and spaces
        for (int i = 0; i < strlen(name); i++)
        {
            if (!isalpha(name[i]) && name[i] != ' ')
            {
                printf("Invalid input! Name can only contain letters and spaces.\n");
                name[0] = '\0';
                break;
            }
        }
        getchar();

    } while (strlen(name) == 0);

    printf("\nGreat! Your name is: %s\n", name);

    // validate age input
    do
    {
        printf("Please enter your age: ");
        scanf("%d", &age);

        // check if age is between 0 and 120
        if (age < 0 || age > 120)
        {
            printf("Invalid input! Age must be between 0 and 120.\n");
            age = -1;
        }
        getchar();

    } while (age == -1);

    printf("\nAwesome! You are %d years old.\n", age);

    // validate GPA input
    do
    {
        printf("Please enter your GPA: ");
        scanf("%f", &gpa);

        // check if GPA is between 0.0 and 4.0
        if (gpa < 0.0 || gpa > 4.0)
        {
            printf("Invalid input! GPA must be between 0.0 and 4.0.\n");
            gpa = -1.0;
        }
        getchar();

    } while (gpa == -1.0);

    printf("\nPerfect! Your current GPA is: %.2f\n", gpa);

    // display final message
    printf("\nThank you for sharing your information with us!\n");

    return 0;
}