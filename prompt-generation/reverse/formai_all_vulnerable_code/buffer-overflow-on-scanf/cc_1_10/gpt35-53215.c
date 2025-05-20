//FormAI DATASET v1.0 Category: Hotel Management System ; Style: realistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct guest{
    char name[50];
    int room_no;
    char check_in_date[20];
}g;

void add_guest(){
    printf("\nEnter guest name: ");
    scanf("%s", g.name);
    printf("Enter room number: ");
    scanf("%d", &g.room_no);
    printf("Enter check-in date(dd/mm/yyyy): ");
    scanf("%s", g.check_in_date);
    FILE *fp;
    fp = fopen("guests.txt", "a");
    if(fp == NULL){
        printf("Error opening file\n");
        return;
    }
    fprintf(fp, "%s %d %s\n", g.name, g.room_no, g.check_in_date);
    printf("\nGuest added successfully.\n");
    fclose(fp);
}

void view_guests(){
    FILE *fp;
    fp = fopen("guests.txt", "r");
    if(fp == NULL){
        printf("Error opening file\n");
        return;
    }
    printf("\nList of guests:\n");
    printf("------------------------------\n");
    printf("Name\tRoom No.\tCheck-in date\n");
    printf("------------------------------\n");
    while(fscanf(fp, "%s %d %s", g.name, &g.room_no, g.check_in_date) != EOF){
        printf("%s\t%d\t\t%s\n", g.name, g.room_no, g.check_in_date);
    }
    printf("------------------------------\n");
    fclose(fp);
}

void search_guest(){
    FILE *fp;
    fp = fopen("guests.txt", "r");
    if(fp == NULL){
        printf("Error opening file\n");
        return;
    }
    char name[50];
    printf("\nEnter name of the guest: ");
    scanf("%s", name);
    int found = 0;
    while(fscanf(fp, "%s %d %s", g.name, &g.room_no, g.check_in_date) != EOF){
        if(strcmp(name, g.name) == 0){
            printf("\nGuest details:\n");
            printf("------------------------------\n");
            printf("Name\tRoom No.\tCheck-in date\n");
            printf("------------------------------\n");
            printf("%s\t%d\t\t%s\n", g.name, g.room_no, g.check_in_date);
            printf("------------------------------\n");
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("\nGuest not found.");
    }
    fclose(fp);
}

void delete_guest(){
    FILE *fp1, *fp2;
    fp1 = fopen("guests.txt", "r");
    if(fp1 == NULL){
        printf("Error opening file\n");
        return;
    }
    fp2 = fopen("temp.txt", "w");
    if(fp2 == NULL){
        printf("Error opening file\n");
        fclose(fp1);
        return;
    }
    char name[50];
    printf("\nEnter name of the guest: ");
    scanf("%s", name);
    int found = 0;
    while(fscanf(fp1, "%s %d %s", g.name, &g.room_no, g.check_in_date) != EOF){
        if(strcmp(name, g.name) == 0){
            found = 1;
        }
        else{
            fprintf(fp2, "%s %d %s\n", g.name, g.room_no, g.check_in_date);
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found == 0){
        printf("\nGuest not found.");
        remove("temp.txt");
    }
    else{
        remove("guests.txt");
        rename("temp.txt", "guests.txt");
        printf("\nGuest deleted successfully.");
    }
}

int main(){
    int choice;
    while(1){
        printf("\n\nHotel Management System\n");
        printf("1. Add guest\n");
        printf("2. View guests\n");
        printf("3. Search guest\n");
        printf("4. Delete guest\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_guest();
                break;
            case 2:
                view_guests();
                break;
            case 3:
                search_guest();
                break;
            case 4:
                delete_guest();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}