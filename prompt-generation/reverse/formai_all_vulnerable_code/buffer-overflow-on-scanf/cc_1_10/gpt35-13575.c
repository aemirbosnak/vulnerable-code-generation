//FormAI DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("Welcome to the Happy Error Handling example program!\n\n");

    int num;
    printf("Enter a number between 1 and 10: ");
    scanf("%d", &num);

    if(num < 1 || num > 10){
        printf("Oops! You entered a number out of range.\n");

        #ifndef DEBUG
            printf("Please enter a number within the given range.\n");
        #endif

        #ifdef DEBUG
            fprintf(stderr, "Invalid number entered. Terminating the program.\n");
            exit(1);
        #endif
    }
    else{
        printf("Great! You entered a valid number: %d\n", num);
    }

    char str[10];
    printf("\nEnter a string: ");
    scanf("%s", str);

    if(strlen(str) > 5){
        printf("Uh-oh! You entered a string that is too long.\n");

        #ifndef DEBUG
            printf("Please enter a smaller string.\n");
        #endif

        #ifdef DEBUG
            fprintf(stderr, "Invalid string entered. Terminating the program.\n");
            exit(1);
        #endif
    }
    else{
        printf("Awesome! You entered a valid string: %s\n", str);
    }

    int arr[5];
    printf("\nEnter elements of an array of size 5: ");
    for(int i=0; i<5; i++){
        scanf("%d", &arr[i]);
    }

    printf("Your array looks like this: ");
    for(int i=0; i<5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    if(arr[0] > arr[4]){
        printf("Oh no! The first element of the array is greater than the last.\n");

        #ifndef DEBUG
            printf("Please ensure that the first element is smaller than the last.\n");
        #endif

        #ifdef DEBUG
            fprintf(stderr, "Invalid array entered. Terminating the program.\n");
            exit(1);
        #endif
    }
    else{
        printf("Fantastic! Your array is valid.\n");
    }

    printf("\nCongratulations! You made it to the end of the program without any errors!\n");

    return 0;
}