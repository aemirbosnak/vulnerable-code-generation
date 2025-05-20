//FormAI DATASET v1.0 Category: Hotel Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int room_num;
    char address[100];
    char phone_num[20];
    char email[50];
    char check_in[20];
    char check_out[20];
    double room_price;
} guest;

int main() {
    FILE *fp;
    guest g;
    char choice;
    int num_guests = 0;

    fp = fopen("Guests.txt", "a");

    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    do {
        printf("\nMENU\n");
        printf("1. Check In\n");
        printf("2. Check Out\n");
        printf("3. Exit\n");

        printf("Enter a choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                printf("\nEnter guest name: ");
                scanf("%s", g.name);

                printf("Enter room number: ");
                scanf("%d", &g.room_num);

                printf("Enter address: ");
                scanf("%s", g.address);

                printf("Enter phone number: ");
                scanf("%s", g.phone_num);

                printf("Enter email: ");
                scanf("%s", g.email);

                printf("Enter check-in date (mm/dd/yyyy): ");
                scanf("%s", g.check_in);

                printf("Enter check-out date (mm/dd/yyyy): ");
                scanf("%s", g.check_out);

                printf("Enter room price: ");
                scanf("%lf", &g.room_price);

                fwrite(&g, sizeof(guest), 1, fp);
                num_guests++;
                break;
            case '2':
                if(num_guests == 0) {
                    printf("No guests to check out.\n");
                } else {
                    guest temp;
                    FILE *temp_fp;

                    temp_fp = fopen("temp.txt", "w");
                    rewind(fp);

                    printf("\nEnter room number: ");
                    int room_num;
                    scanf("%d", &room_num);

                    while(fread(&temp, sizeof(guest), 1, fp)) {
                        if(temp.room_num == room_num) {
                            printf("\nGuest Name: %s\n", temp.name);
                            printf("Room Number: %d\n", temp.room_num);
                            printf("Address: %s\n", temp.address);
                            printf("Phone Number: %s\n", temp.phone_num);
                            printf("Email: %s\n", temp.email);
                            printf("Check-in Date: %s\n", temp.check_in);
                            printf("Check-out Date: %s\n", temp.check_out);
                            printf("Room Price: %.2lf\n", temp.room_price);

                            printf("CHECK OUT (y/n)? ");
                            char check_out_choice;
                            scanf(" %c", &check_out_choice);

                            if(check_out_choice == 'y' || check_out_choice == 'Y') {
                                printf("Successfully checked out.\n");
                            } else {
                                fwrite(&temp, sizeof(guest), 1, temp_fp);
                            }
                        } else {
                            fwrite(&temp, sizeof(guest), 1, temp_fp);
                        }
                    }
                    fclose(fp);
                    fclose(temp_fp);

                    remove("Guests.txt");
                    rename("temp.txt", "Guests.txt");

                    fp = fopen("Guests.txt", "a");
                    num_guests--;
                }
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != '3');

    fclose(fp);
    return 0;
}