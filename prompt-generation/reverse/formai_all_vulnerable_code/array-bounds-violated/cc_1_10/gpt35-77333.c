//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Sherlock Holmes
#include <stdio.h>

// A Performance-Critical Component program to solve the Mystery of the Missing Numbers

int main(){
    int i, j, k, flag;
    int arr1[10] = {1, 2, 4, 5, 7, 8, 9, 10, 12, 13};
    int arr2[15] = {4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 17, 18, 19};

    printf("The Mystery of the Missing Numbers\n");

    //Sherlock's analysis
    printf("Sherlock Holmes: Watson, the two arrays you see before us hold the key to this mystery. ");
    printf("As you can see, the arrays are missing some numbers. Let us investigate.\n\n");

    printf("Watson: Yes, I see that arr1 is missing 3, 6 and 11, while arr2 is missing 1, 2 and 3.\n");

    //Sherlock's deduction
    printf("Sherlock Holmes: Watson, there must be a pattern to these missing numbers. Let us investigate.\n\n");

    printf("Watson: Well, there seems to be a gap of 1 between the elements of arr2, ");
    printf("while arr1 has alternate elements missing between 3 and 11.\n");

    //Sherlock's implementation
    printf("Sherlock Holmes: Watson, we can now implement our solution to this mystery. ");
    printf("We shall first fill the missing numbers in arr1, and then in arr2 using the gap of 1.\n");

    printf("Watson: Excellent idea, Sherlock! Let us proceed.\n\n");

    //filling arr1
    i = 0;
    while(i < 10){
        flag = 0;
        for(j = arr1[i-1]+1; j < arr1[i]; j++){
            arr1[i-flag] = j;
            flag++;
        }
        i++;
    }

    //filling arr2
    k = 0;
    for(i = 1; i <= 20; i++){
        if(arr2[k] != i){
            for(j = 0; j < 3; j++){
                arr2[k+j] = i+j;
            }
            k += 3;
        }
        else{
            k++;
        }
    }

    //print the filled arrays
    printf("Sherlock Holmes: Watson, our solution was successful. ");
    printf("Please take a look at the filled arrays below.\n\n");

    for(i = 0; i < 10; i++){
        printf("%d ", arr1[i]);
    }
    printf("\n");

    for(i = 0; i < 15; i++){
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}