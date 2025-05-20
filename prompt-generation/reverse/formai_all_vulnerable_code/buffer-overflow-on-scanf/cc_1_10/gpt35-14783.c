//FormAI DATASET v1.0 Category: Arithmetic ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random numbers between 1 and 100
int generateRandomNumber(){
    srand(time(NULL));
    int random_number = rand()%100 + 1; //generating random number between 1 and 100
    return random_number;
}

int main(){
    int num_array[10]; //integer array
    int sum = 0; //variable to hold the sum of array elements
    int product = 1; //variable to hold the product of array elements
    printf("Let's play with some arithmetic calculations!\n\n");

    //Getting input from user for array elements
    printf("Enter 10 integer values:\n");
    for(int i=0;i<10;i++){
        scanf("%d",&num_array[i]);
    }

    //Printing the array elements
    printf("\nYou entered the following values:\n");
    for(int i=0;i<10;i++){
        printf("%d ",num_array[i]);
    }

    //Calculating sum of array elements
    printf("\n\nCalculating the sum of array elements...\n");
    for(int i=0;i<10;i++){
        sum += num_array[i]; //adding each element to sum
    }
    printf("The sum of array elements is %d\n",sum);

    //Calculating product of array elements
    printf("\nCalculating the product of array elements...\n");
    for(int i=0;i<10;i++){
        product *= num_array[i]; //multiplying each element to product
    }
    printf("The product of array elements is %d\n",product);

    //Generating random number between 1 and 100
    printf("\nGenerating a random number between 1 and 100...\n");
    int random_number = generateRandomNumber();
    printf("The random number generated is %d\n",random_number);

    //Checking if random number is greater than or equal to sum and product
    if(random_number >= sum && random_number >= product){
        printf("\nThe random number %d is greater than or equal to both sum and product of array elements!\n",random_number);
    }
    else if(random_number >= sum){
        printf("\nThe random number %d is greater than or equal to sum of array elements!\n",random_number);
    }
    else if(random_number >= product){
        printf("\nThe random number %d is greater than or equal to product of array elements!\n",random_number);
    }
    else{
        printf("\nThe random number %d is greater than neither sum nor product of array elements!\n",random_number);
    }

    return 0;
}