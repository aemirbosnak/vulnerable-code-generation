//FormAI DATASET v1.0 Category: Funny ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//The following structure is used as an object to store data about cars
struct car{
    char model[20];
    int year;
    float price;
};

int main(){
    printf("Welcome to the car inventory management system!\n");

    //Creating an array of cars
    struct car cars[10];

    //Starting the data entry process
    for(int i=0;i<10;i++){
        printf("Enter the model of car %d: ",i+1);
        fgets(cars[i].model,20,stdin);
        printf("Enter the year of car %d: ",i+1);
        scanf("%d",&cars[i].year);
        printf("Enter the price of car %d: ",i+1);
        scanf("%f",&cars[i].price);
        getchar(); //used to clear the input buffer after each input
        printf("\n");
    }

    //Displaying the inventory
    printf("The current inventory is:\n");
    printf("Model\t\tYear\t\tPrice\n");
    for(int i=0;i<10;i++){
        printf("%s\t\t%d\t\t%.2f\n",cars[i].model,cars[i].year,cars[i].price);
    }

    //Performing a search on the basis of model
    char search_model[20];
    printf("\nEnter the model you want to search for: ");
    fgets(search_model,20,stdin);
    int found = 0;
    for(int i=0;i<10;i++){
        if(strcmp(cars[i].model,search_model) == 0){
            printf("The car with model '%s' is present in the inventory at position %d\n",search_model,i);
            found = 1;
        }
    }
    if(!found){
        printf("Sorry, the car with model '%s' is not present in the inventory\n",search_model);
    }

    //Sorting the inventory on the basis of price
    for(int i=0;i<9;i++){
        for(int j=0;j<9-i;j++){
            if(cars[j].price > cars[j+1].price){
                struct car temp = cars[j];
                cars[j] = cars[j+1];
                cars[j+1] = temp;
            }
        }
    }
    printf("\nThe inventory sorted on the basis of price is:\n");
    printf("Model\t\tYear\t\tPrice\n");
    for(int i=0;i<10;i++){
        printf("%s\t\t%d\t\t%.2f\n",cars[i].model,cars[i].year,cars[i].price);
    }

    //Calculating the average price of cars
    float sum = 0;
    for(int i=0;i<10;i++){
        sum += cars[i].price;
    }
    float avg_price = sum/10.0;
    printf("\nThe average price of cars in the inventory is %.2f\n",avg_price);

    //Exiting the program
    printf("\nThank you for using the program!\n");
    return 0;
}