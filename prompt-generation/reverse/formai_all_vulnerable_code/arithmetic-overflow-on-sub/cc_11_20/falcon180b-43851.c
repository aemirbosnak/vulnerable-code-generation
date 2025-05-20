//Falcon-180B DATASET v1.0 Category: Data mining ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 10000

struct item{
    int id;
    float price;
    int quantity;
};

struct item data[MAX_SIZE];

int main(){
    int i, n, choice;
    float sum=0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Enter the id, price and quantity of item %d:\n", i+1);
        scanf("%d %f %d", &data[i].id, &data[i].price, &data[i].quantity);
        sum+=data[i].price*data[i].quantity;
    }

    printf("Total sales: $%.2f\n", sum);

    do{
        printf("\n1. Sort by ID\n2. Sort by Price\n3. Sort by Quantity\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                for(i=0; i<n-1; i++){
                    if(data[i].id > data[i+1].id){
                        struct item temp = data[i];
                        data[i] = data[i+1];
                        data[i+1] = temp;
                    }
                }
                printf("Sorted by ID:\n");
                for(i=0; i<n; i++){
                    printf("%d %f %d\n", data[i].id, data[i].price, data[i].quantity);
                }
                break;

            case 2:
                for(i=0; i<n-1; i++){
                    if(data[i].price > data[i+1].price){
                        struct item temp = data[i];
                        data[i] = data[i+1];
                        data[i+1] = temp;
                    }
                }
                printf("Sorted by Price:\n");
                for(i=0; i<n; i++){
                    printf("%d %f %d\n", data[i].id, data[i].price, data[i].quantity);
                }
                break;

            case 3:
                for(i=0; i<n-1; i++){
                    if(data[i].quantity > data[i+1].quantity){
                        struct item temp = data[i];
                        data[i] = data[i+1];
                        data[i+1] = temp;
                    }
                }
                printf("Sorted by Quantity:\n");
                for(i=0; i<n; i++){
                    printf("%d %f %d\n", data[i].id, data[i].price, data[i].quantity);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }

    }while(choice!=4);

    return 0;
}