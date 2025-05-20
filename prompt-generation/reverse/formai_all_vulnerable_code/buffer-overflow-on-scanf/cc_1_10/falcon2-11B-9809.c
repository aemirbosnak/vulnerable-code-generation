//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

struct Patient {
    char name[100];
    char address[200];
    char phone[20];
};

int main() {
    struct Patient patient;
    int choice, id;
    char name[100], address[200], phone[20];

    printf("Medical Store Management System\n");
    printf("1. Add Patient\n");
    printf("2. Delete Patient\n");
    printf("3. Update Patient\n");
    printf("4. List Patients\n");
    printf("5. Exit\n");

    printf("\nPlease choose an option:\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter Patient Name:\n");
            scanf("%s", name);
            printf("Enter Patient Address:\n");
            scanf("%s", address);
            printf("Enter Patient Phone Number:\n");
            scanf("%s", phone);
            printf("Enter Patient ID:\n");
            scanf("%d", &id);
            printf("Patient added successfully.\n");
            break;
        case 2:
            printf("Enter Patient ID:\n");
            scanf("%d", &id);
            printf("Patient deleted successfully.\n");
            break;
        case 3:
            printf("Enter Patient ID:\n");
            scanf("%d", &id);
            printf("Enter Patient Name:\n");
            scanf("%s", name);
            printf("Enter Patient Address:\n");
            scanf("%s", address);
            printf("Enter Patient Phone Number:\n");
            scanf("%s", phone);
            printf("Patient updated successfully.\n");
            break;
        case 4:
            printf("Patient List:\n");
            printf("Patient ID | Name | Address | Phone\n");
            printf("-------------------------------------\n");
            printf("%d | %s | %s | %s\n", id, name, address, phone);
            break;
        case 5:
            printf("Thank you for using Medical Store Management System.\n");
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }

    return 0;
}