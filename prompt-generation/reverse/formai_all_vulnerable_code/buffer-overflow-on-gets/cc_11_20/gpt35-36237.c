//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicine { // structure of medicine
    int id;
    char name[50];
    float price;
    int quantity;
} Medicine;

int main() {
    int choice;
    int num_med;

    printf("[C] Medical Store Management System");

    printf("\n\nEnter the number of medicines in the store: ");
    scanf("%d", &num_med);
    getchar(); // to clear input buffer

    Medicine *med_arr = (Medicine *) malloc(num_med * sizeof(Medicine)); // dynamic allocation of memory

    printf("Enter details of all medicines:\n");
    for (int i=0; i<num_med; i++) {
        printf("\nDetails of Medicine %d:\n", i+1);
        med_arr[i].id = i+1;
        printf("Enter name: ");
        gets(med_arr[i].name);
        printf("Enter price: ");
        scanf("%f", &med_arr[i].price);
        printf("Enter quantity: ");
        scanf("%d", &med_arr[i].quantity);
        getchar(); // to clear input buffer
    }
    
    do {
        printf("\n\nMENU\n");
        printf("1. Display all medicines\n");
        printf("2. Add a new medicine\n");
        printf("3. Update details of a medicine\n");
        printf("4. Delete a medicine\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // to clear input buffer

        switch(choice) {
            case 1:
                printf("\n\nMEDICINE LIST:\n");
                for (int i=0; i<num_med; i++) {
                    printf("%d. Name: %s\tPrice: %.2f\tQuantity: %d\n", med_arr[i].id, med_arr[i].name, med_arr[i].price, med_arr[i].quantity);
                }
                break;

            case 2:
                printf("\n\nEnter details of new medicine:\n");
                num_med++;
                med_arr = (Medicine *) realloc(med_arr, num_med * sizeof(Medicine)); // reallocation of memory
                med_arr[num_med-1].id = num_med;

                printf("Enter name: ");
                gets(med_arr[num_med-1].name);
                printf("Enter price: ");
                scanf("%f", &med_arr[num_med-1].price);
                printf("Enter quantity: ");
                scanf("%d", &med_arr[num_med-1].quantity);
                getchar(); // to clear input buffer
                printf("\nNew medicine added!");
                break;

            case 3:
                printf("\nEnter id of medicine to update: ");
                int update_id;
                scanf("%d", &update_id);
                getchar(); // to clear input buffer

                if (update_id <= 0 || update_id > num_med) {
                    printf("\nInvalid id! Please try again.");
                }
                else {
                    printf("\nDetails of Medicine %d:\n", update_id);
                    printf("Name: %s\tPrice: %.2f\tQuantity: %d\n", med_arr[update_id-1].name, med_arr[update_id-1].price, med_arr[update_id-1].quantity);

                    printf("\nEnter updated details:\n");
                    printf("Enter name: ");
                    gets(med_arr[update_id-1].name);
                    printf("Enter price: ");
                    scanf("%f", &med_arr[update_id-1].price);
                    printf("Enter quantity: ");
                    scanf("%d", &med_arr[update_id-1].quantity);
                    getchar(); // to clear input buffer
                    printf("\nMedicine details updated!");
                }
                break;

            case 4:
                printf("\nEnter id of medicine to delete: ");
                int delete_id;
                scanf("%d", &delete_id);
                getchar(); // to clear input buffer

                if (delete_id <= 0 || delete_id > num_med) {
                    printf("\nInvalid id! Please try again.");
                }
                else {
                    for (int i=delete_id-1; i<num_med-1; i++) { // shift elements in array
                        med_arr[i] = med_arr[i+1];
                        med_arr[i].id--;
                    }
                    num_med--;
                    med_arr = (Medicine *) realloc(med_arr, num_med * sizeof(Medicine)); // reallocation of memory
                    printf("\nMedicine deleted!");
                }
                break;

            case 5:
                printf("\nExiting...Thank you for using our system :)");
                break;

            default:
                printf("\nInvalid choice! Please try again.");
        }

    } while (choice != 5);

    free(med_arr); // free memory allocated by malloc

    return 0;
}