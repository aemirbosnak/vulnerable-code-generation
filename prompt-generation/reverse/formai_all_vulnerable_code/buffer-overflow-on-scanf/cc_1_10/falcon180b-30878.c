//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include<stdbool.h>

#define MAX 1000

struct stock{
    char name[20];
    float price;
    float change;
};

void add_stock(struct stock* s, int* count){
    printf("Enter stock name: ");
    scanf("%s", s[*count].name);
    printf("Enter stock price: ");
    scanf("%f", &s[*count].price);
    s[*count].change = 0;
    (*count)++;
}

void display_stock(struct stock s[], int count){
    printf("\nStock name\tPrice\tChange\n");
    for(int i=0; i<count; i++){
        printf("%s\t%f\t%f\n", s[i].name, s[i].price, s[i].change);
    }
}

void update_stock(struct stock* s, int count){
    printf("Enter stock index: ");
    int index;
    scanf("%d", &index);

    if(index >= 0 && index < count){
        printf("Enter new stock price: ");
        scanf("%f", &s[index].price);
        s[index].change = s[index].price - s[index].price;
    }
    else{
        printf("Invalid stock index\n");
    }
}

void delete_stock(struct stock* s, int* count){
    printf("Enter stock index: ");
    int index;
    scanf("%d", &index);

    if(index >= 0 && index < *count){
        for(int i=index; i<*count-1; i++){
            strcpy(s[i].name, s[i+1].name);
            s[i].price = s[i+1].price;
            s[i].change = s[i+1].change;
        }
        (*count)--;
    }
    else{
        printf("Invalid stock index\n");
    }
}

int main(){
    struct stock s[MAX];
    int count = 0;

    while(true){
        system("clear");
        printf("\n");
        printf("1. Add stock\n");
        printf("2. Display stocks\n");
        printf("3. Update stock price\n");
        printf("4. Delete stock\n");
        printf("0. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_stock(s, &count);
                break;
            case 2:
                display_stock(s, count);
                break;
            case 3:
                update_stock(s, count);
                break;
            case 4:
                delete_stock(s, &count);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}