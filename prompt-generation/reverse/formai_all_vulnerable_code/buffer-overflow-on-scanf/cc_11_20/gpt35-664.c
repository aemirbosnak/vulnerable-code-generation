//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: immersive
#include<stdio.h>

int main(){
    int warehouse[10][10]; //initialize warehouse with 100 spaces (10x10)
    int i, j, choice, product;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            warehouse[i][j] = 0; //initialize all spaces to be empty
        }
    }
    printf("***Warehouse Management System***\n");
    while(1){
        printf("\nChoose an option:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display all products\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter product number: ");
                scanf("%d", &product);
                printf("Enter x coordinate: ");
                scanf("%d", &i);
                printf("Enter y coordinate: ");
                scanf("%d", &j);
                if(i>=0 && i<10 && j>=0 && j<10 && warehouse[i][j]==0){ //check if space is within warehouse and empty
                    warehouse[i][j] = product; //add product to specified space
                    printf("Product %d added to (%d,%d)\n", product, i, j);
                }
                else{
                    printf("Invalid input or space already occupied. Try again.\n");
                }
                break;
            case 2:
                printf("Enter x coordinate: ");
                scanf("%d", &i);
                printf("Enter y coordinate: ");
                scanf("%d", &j);
                if(i>=0 && i<10 && j>=0 && j<10 && warehouse[i][j]!=0){ //check if space is within warehouse and occupied
                    product = warehouse[i][j]; //retrieve product from specified space
                    warehouse[i][j] = 0; //empty specified space
                    printf("Product %d removed from (%d,%d)\n", product, i, j);
                }
                else{
                    printf("Invalid input or space already empty. Try again.\n");
                }
                break;
            case 3:
                printf("Warehouse contents:\n");
                for(i=0;i<10;i++){
                    for(j=0;j<10;j++){
                        printf("%d ", warehouse[i][j]); //display contents of all spaces in warehouse
                    }
                    printf("\n");
                }
                break;
            case 4:
                printf("Exiting...");
                return 0;
            default:
                printf("Invalid input. Try again.\n");
        }
    }
}