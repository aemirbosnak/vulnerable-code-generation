//Falcon-180B DATASET v1.0 Category: Recursive ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

//Function to print a string in reverse order
void printReverse(char str[], int start, int end){
    char temp;
    while(start < end){
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
        start++;
        end--;
    }
}

//Function to check if a string is a palindrome
int isPalindrome(char str[], int size){
    int i = 0;
    while(i < size/2){
        if(*(str+i)!= *(str+size-i-1)){
            return 0;
        }
        i++;
    }
    return 1;
}

//Recursive function to generate all permutations of a string
void permute(char str[], int left, int right){
    int i;
    if(left == right){
        printf("%s ", str);
        return;
    }
    for(i = left; i <= right; i++){
        str[left] = *(str+i);
        permute(str, left+1, right);
    }
}

int main(){
    char str[100];
    int size;

    //Get input from user
    printf("Enter a string: ");
    scanf("%s", str);
    size = strlen(str);

    //Check if the string is a palindrome
    if(isPalindrome(str, size)){
        printf("The string is a palindrome.\n");
    }
    else{
        printf("The string is not a palindrome.\n");
    }

    //Print the string in reverse order
    printf("The string in reverse order is: ");
    printReverse(str, 0, size-1);
    printf("\n");

    //Generate all permutations of the string
    printf("All permutations of the string are:\n");
    permute(str, 0, size-1);

    return 0;
}