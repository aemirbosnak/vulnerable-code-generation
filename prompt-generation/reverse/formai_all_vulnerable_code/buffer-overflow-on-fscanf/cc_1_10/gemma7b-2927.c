//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void display_menu()
{
    printf("\n");
    printf("--------------------------------------------------------");
    printf("\n");
    printf("1. Register Student\n");
    printf("2. Login Student\n");
    printf("3. View Results\n");
    printf("4. Exit\n");
    printf("\n");
    printf("Enter your choice: ");
}

void register_student()
{
    printf("Enter your name: ");
    char name[MAX];
    scanf("%s", name);

    printf("Enter your email address: ");
    char email[MAX];
    scanf("%s", email);

    printf("Enter your phone number: ");
    int phone_number;
    scanf("%d", &phone_number);

    // Store student data in a file
    FILE *fp = fopen("students.txt", "a");
    fprintf(fp, "%s, %s, %d\n", name, email, phone_number);
    fclose(fp);

    printf("Student registered successfully!\n");
}

void login_student()
{
    printf("Enter your email address: ");
    char email[MAX];
    scanf("%s", email);

    printf("Enter your password: ");
    char password[MAX];
    scanf("%s", password);

    // Compare student data with stored data
    FILE *fp = fopen("students.txt", "r");
    char student_email[MAX];
    char student_password[MAX];
    int student_phone_number;
    int i = 0;
    while (fscanf(fp, "%s, %s, %d\n", student_email, student_password, &student_phone_number) != EOF)
    {
        if (strcmp(email, student_email) == 0 && strcmp(password, student_password) == 0)
        {
            printf("Welcome, %s!\n", student_email);
            break;
        }
        i++;
    }
    if (i == MAX)
    {
        printf("Invalid email or password.\n");
    }
    fclose(fp);
}

void view_results()
{
    printf("Enter your email address: ");
    char email[MAX];
    scanf("%s", email);

    // Retrieve student results from file
    FILE *fp = fopen("results.txt", "r");
    char student_email[MAX];
    int student_marks[MAX];
    int i = 0;
    while (fscanf(fp, "%s, %d\n", student_email, &student_marks) != EOF)
    {
        if (strcmp(email, student_email) == 0)
        {
            printf("Your results:\n");
            for (int j = 0; j < MAX; j++)
            {
                if (student_marks[j] != 0)
                {
                    printf("%d ", student_marks[j]);
                }
            }
            printf("\n");
            break;
        }
        i++;
    }
    if (i == MAX)
    {
        printf("Invalid email or results not available.\n");
    }
    fclose(fp);
}

int main()
{
    int choice;

    display_menu();
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            register_student();
            break;
        case 2:
            login_student();
            break;
        case 3:
            view_results();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}