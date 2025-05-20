//FormAI DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[50];
    char address[100];
    char phone[15];
    int room_number;
    int num_days;
    float total_cost;
};

void new_guest() {
    FILE *fp;
    struct guest g;
    fp = fopen("hotel.txt", "a");
    printf("Enter guest name: ");
    scanf("%[^\n]%*c", g.name);
    printf("Enter guest address: ");
    scanf("%[^\n]%*c", g.address);
    printf("Enter guest phone number: ");
    scanf("%[^\n]%*c", g.phone);
    printf("Enter guest room number: ");
    scanf("%d", &g.room_number);
    printf("Enter number of days staying: ");
    scanf("%d", &g.num_days);
    g.total_cost = g.num_days * 100;
    fprintf(fp, "%s|%s|%s|%d|%d|%0.2f\n", g.name, g.address, g.phone, g.room_number, g.num_days, g.total_cost);
    fclose(fp);
    printf("Guest added successfully!\n");
}

void search_guest() {
    FILE *fp;
    char name[50];
    struct guest g;
    fp = fopen("hotel.txt", "r");
    printf("Enter guest name to search: ");
    scanf("%[^\n]%*c", name);
    while(fscanf(fp, "%[^|]|%[^|]|%[^|]|%d|%d|%f\n", g.name, g.address, g.phone, &g.room_number, &g.num_days, &g.total_cost) != EOF) {
        if(strcmp(name, g.name) == 0) {
            printf("Guest found!\nName: %s\nAddress: %s\nPhone: %s\nRoom Number: %d\nNumber of Days Staying: %d\nTotal Cost: %0.2f\n", g.name, g.address, g.phone, g.room_number, g.num_days, g.total_cost);
            fclose(fp);
            return;
        }
    }
    printf("Guest not found!\n");
    fclose(fp);
}

void update_guest() {
    FILE *fp;
    char name[50], choice;
    struct guest g;
    long int pos;
    fp = fopen("hotel.txt", "r+");
    printf("Enter guest name to update: ");
    scanf("%[^\n]%*c", name);
    while(fscanf(fp, "%[^|]|%[^|]|%[^|]|%d|%d|%f\n", g.name, g.address, g.phone, &g.room_number, &g.num_days, &g.total_cost) != EOF) {
        if(strcmp(name, g.name) == 0) {
            printf("Guest found!\nName: %s\nAddress: %s\nPhone: %s\nRoom Number: %d\nNumber of Days Staying: %d\nTotal Cost: %0.2f\n", g.name, g.address, g.phone, g.room_number, g.num_days, g.total_cost);
            printf("Choose what to update:\na. Name\nb. Address\nc. Phone Number\nd. Room Number\ne. Number of Days Staying\n");
            scanf(" %c", &choice);
            switch(choice) {
                case 'a':
                    printf("Enter new name: ");
                    scanf("%[^\n]%*c", g.name);
                    break;
                case 'b':
                    printf("Enter new address: ");
                    scanf("%[^\n]%*c", g.address);
                    break;
                case 'c':
                    printf("Enter new phone number: ");
                    scanf("%[^\n]%*c", g.phone);
                    break;
                case 'd':
                    printf("Enter new room number: ");
                    scanf("%d", &g.room_number);
                    break;
                case 'e':
                    printf("Enter new number of days staying: ");
                    scanf("%d", &g.num_days);
                    g.total_cost = g.num_days * 100;
                    break;
                default:
                    printf("Invalid choice!\n");
                    fclose(fp);
                    return;
            }
            pos = ftell(fp);
            fseek(fp, pos - strlen(g.name) - strlen(g.address) - strlen(g.phone) - 13, SEEK_SET);
            fprintf(fp, "%s|%s|%s|%d|%d|%0.2f\n", g.name, g.address, g.phone, g.room_number, g.num_days, g.total_cost);
            fclose(fp);
            printf("Guest updated successfully!\n");
            return;
        }
    }
    printf("Guest not found!\n");
    fclose(fp);
}

void checkout_guest() {
    FILE *fp, *tmp;
    char name[50];
    struct guest g;
    fp = fopen("hotel.txt", "r");
    tmp = fopen("tmp.txt", "w");
    printf("Enter guest name to checkout: ");
    scanf("%[^\n]%*c", name);
    while(fscanf(fp, "%[^|]|%[^|]|%[^|]|%d|%d|%f\n", g.name, g.address, g.phone, &g.room_number, &g.num_days, &g.total_cost) != EOF) {
        if(strcmp(name, g.name) == 0) {
            printf("Guest found!\nName: %s\nAddress: %s\nPhone: %s\nRoom Number: %d\nNumber of Days Staying: %d\nTotal Cost: %0.2f\n", g.name, g.address, g.phone, g.room_number, g.num_days, g.total_cost);
            printf("Are you sure you want to checkout %s? (y/n): ", g.name);
            if(getchar() == 'y') {
                continue;
            }
        }
        fprintf(tmp, "%s|%s|%s|%d|%d|%0.2f\n", g.name, g.address, g.phone, g.room_number, g.num_days, g.total_cost);
    }
    fclose(fp);
    fclose(tmp);
    remove("hotel.txt");
    rename("tmp.txt", "hotel.txt");
    printf("Guest checkout successful!\n");
}

int main() {
    int choice;
    while(1) {
        printf("***********WELCOME TO C HOTEL MANAGEMENT SYSTEM*************\n");
        printf("\nMENU:\n1. Register new Guest\n2. Search for Guest\n3. Update Guest information\n4. Checkout Guest\n5. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                new_guest();
                break;
            case 2:
                search_guest();
                break;
            case 3:
                update_guest();
                break;
            case 4:
                checkout_guest();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
        printf("\n");
    }
    return 0;
}