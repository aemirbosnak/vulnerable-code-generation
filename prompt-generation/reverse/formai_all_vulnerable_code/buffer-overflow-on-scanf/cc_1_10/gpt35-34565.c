//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
    int id;
    char name[50];
    int quantity;
    float price;
}m[100];

int count = 0;

void insert(){
    int i;
    printf("Enter medicine id: ");
    scanf("%d", &m[count].id);
    printf("Enter medicine name: ");
    scanf("%s", m[count].name);
    printf("Enter medicine quantity: ");
    scanf("%d", &m[count].quantity);
    printf("Enter medicine price: ");
    scanf("%f", &m[count].price);
    count++;
    printf("Medicine added successfully!\n\n");
}

void searchByID(){
    int id, i, flag = 0;
    printf("Enter medicine id to search: ");
    scanf("%d", &id);
    for(i = 0; i < count; i++){
        if(m[i].id == id){
            flag = 1;
            printf("Medicine found!\n");
            printf("Name: %s\nQuantity: %d\nPrice: %.2f\n\n", m[i].name, m[i].quantity, m[i].price);
            break;
        }
    }
    if(flag == 0){
        printf("Medicine not found!\n\n");
    }
}

void searchByName(){
    char name[50];
    int i, flag = 0;
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    for(i = 0; i < count; i++){
        if(strcmp(m[i].name, name) == 0){
            flag = 1;
            printf("Medicine found!\n");
            printf("ID: %d\nQuantity: %d\nPrice: %.2f\n\n", m[i].id, m[i].quantity, m[i].price);
        }
    }
    if(flag == 0){
        printf("Medicine not found!\n\n");
    }
}

void update(){
    int id, i, flag = 0;
    printf("Enter medicine id to update: ");
    scanf("%d", &id);
    for(i = 0; i < count; i++){
        if(m[i].id == id){
            flag = 1;
            printf("Enter new medicine name: ");
            scanf("%s", m[i].name);
            printf("Enter new medicine quantity: ");
            scanf("%d", &m[i].quantity);
            printf("Enter new medicine price: ");
            scanf("%f", &m[1].price);
            printf("Medicine updated successfully!\n\n");
            break;
        }
    }
    if(flag == 0){
        printf("Medicine not found!\n\n");
    }
}

void delete(){
    int id, i, flag = 0;
    printf("Enter medicine id to delete: ");
    scanf("%d", &id);
    for(i = 0; i < count; i++){
        if(m[i].id == id){
            flag = 1;
            memmove(&m[i], &m[i + 1], sizeof(struct medicine) * (count - i - 1));
            count--;
            printf("Medicine deleted successfully!\n\n");
            break;
        }
    }
    if(flag == 0){
        printf("Medicine not found!\n\n");
    }
}

void display(){
    int i;
    if(count == 0){
        printf("No medicines found!\n\n");
    }
    else{
        printf("ID\tName\tQuantity\tPrice\n");
        for(i = 0; i < count; i++){
            printf("%d\t%s\t%d\t\t%.2f\n", m[i].id, m[i].name, m[i].quantity, m[i].price);
        }
        printf("\n");
    }
}

int main(){
    int choice;
    while(1){
        printf("Enter your choice:\n1. Insert\n2. Search by id\n3. Search by name\n4. Update\n");
        printf("5. Delete\n6. Display\n7. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                searchByID();
                break;
            case 3:
                searchByName();
                break;
            case 4:
                update();
                break;
            case 5:
                delete();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n\n");
        }
    }
    return 0;
}