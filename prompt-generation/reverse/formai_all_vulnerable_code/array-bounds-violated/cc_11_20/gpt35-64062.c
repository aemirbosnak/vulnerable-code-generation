//FormAI DATASET v1.0 Category: Sorting ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello! I am a curious sorting chatbot!\n");
    printf("Please tell me the size of your array:\n");
    int size;
    scanf("%d", &size);
    printf("Great! Now, please enter %d integers one by one:\n", size);
    int arr[size];
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Fascinating! I will now sort your array using Bubble Sort algorithm.\n");
    printf("Just sit back and relax while I do my magic...\n");
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Impressive! Your array has been sorted in ascending order.\n");
    printf("Here is the result:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nBut wait, I am not done yet!\n");
    printf("I am also capable of sorting your array in descending order using Selection Sort algorithm.\n");
    printf("Would you like to proceed? Type 'yes' or 'no':\n");
    char answer[3];
    scanf("%s", answer);
    if(answer[0] == 'y' && answer[1] == 'e' && answer[2] == 's') {
        printf("Fantastic! Let's do it!\n");
        for(int i = 0; i < size-1; i++) {
            int max_index = i;
            for(int j = i+1; j < size; j++) {
                if(arr[j] > arr[max_index]) {
                    max_index = j;
                }
            }
            int temp = arr[max_index];
            arr[max_index] = arr[i];
            arr[i] = temp;
        }
        printf("Superb! Your array has been sorted in descending order.\n");
        printf("Here is the result:\n");
        for(int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\nThank you for using my services! Have a great day!");
    }
    else {
        printf("Oh well, maybe next time. Thank you for using my services!\n");
    }
    return 0;
}