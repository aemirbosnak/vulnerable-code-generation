//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ch;
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    float f1, f2, f3, f4, f5, f6, f7, f8, f9, f10;

    printf("Welcome to the C Medical Store Management System!\n");

    printf("Please select an option:\n");
    printf("1. Register New Patient\n");
    printf("2. View Patient Records\n");
    printf("3. Update Patient Records\n");
    printf("4. Delete Patient Records\n");

    scanf("%c", &ch);

    switch (ch)
    {
        case '1':
            printf("Enter the patient's name:");
            scanf("%s", &f1);

            printf("Enter the patient's age:");
            scanf("%d", &f2);

            printf("Enter the patient's address:");
            scanf("%s", &f3);

            printf("Enter the patient's phone number:");
            scanf("%d", &f4);

            printf("Enter the patient's medical history:");
            scanf("%s", &f5);

            printf("The patient's record has been created.\n");
            break;

        case '2':
            printf("Enter the patient's name:");
            scanf("%s", &f1);

            printf("Patient's records:\n");
            printf("Name: %s\n", f1);
            printf("Age: %d\n", f2);
            printf("Address: %s\n", f3);
            printf("Phone Number: %d\n", f4);
            printf("Medical History: %s\n", f5);
            break;

        case '3':
            printf("Enter the patient's name:");
            scanf("%s", &f1);

            printf("Enter the patient's updated information:\n");
            printf("Name: ");
            scanf("%s", &f1);

            printf("Age: ");
            scanf("%d", &f2);

            printf("Address: ");
            scanf("%s", &f3);

            printf("Phone Number: ");
            scanf("%d", &f4);

            printf("Medical History: ");
            scanf("%s", &f5);

            printf("The patient's record has been updated.\n");
            break;

        case '4':
            printf("Enter the patient's name:");
            scanf("%s", &f1);

            printf("Are you sure you want to delete the patient's record? (Y/N)");
            scanf("%c", &ch);

            if (ch == 'Y')
            {
                printf("The patient's record has been deleted.\n");
            }
            else
            {
                printf("The patient's record has not been deleted.\n");
            }
            break;

        default:
            printf("Invalid input.\n");
    }

    return 0;
}