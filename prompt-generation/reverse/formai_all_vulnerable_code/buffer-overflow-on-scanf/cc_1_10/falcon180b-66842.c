//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct medicine{
    char name[50];
    int price;
    int quantity;
};

void add_medicine(struct medicine *m, int choice){
    printf("Enter medicine name: ");
    scanf("%s", m->name);
    printf("Enter medicine price: ");
    scanf("%d", &m->price);
    printf("Enter medicine quantity: ");
    scanf("%d", &m->quantity);
}

void display_medicine(struct medicine m){
    printf("\nName: %s", m.name);
    printf("\nPrice: %d", m.price);
    printf("\nQuantity: %d", m.quantity);
}

void main(){
    int choice;
    struct medicine m[MAX];
    int i=0;

    while(1){
        printf("\n1.Add Medicine");
        printf("\n2.Display Medicine");
        printf("\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(i==MAX){
                    printf("\nSorry! You cannot add more medicines. ");
                }
                else{
                    add_medicine(&m[i], i);
                    i++;
                }
                break;

            case 2:
                printf("\nName\tPrice\tQuantity");
                for(int j=0; j<i; j++){
                    display_medicine(m[j]);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice! ");
        }
    }
}