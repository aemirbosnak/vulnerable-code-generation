//FormAI DATASET v1.0 Category: Memory Game ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void shuffle(int arr[], int n){
    srand(time(NULL));
    for(int i=n-1; i>0; i--){
        int j = rand()%(i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void play_game(){
    int n;
    printf("Enter the number of elements (even): ");
    scanf("%d", &n);
    if(n%2 != 0){
        printf("Invalid input! Please enter an even number.\n");
        play_game();
    }
    int arr[n];
    for(int i=0; i<n/2; i++){
        arr[i] = arr[i+n/2] = i+1;
    }
    shuffle(arr, n);
    int temp[n], count=0;
    for(int i=0; i<n; i++){
        temp[i] = 0;
    }
    while(1){
        display(temp, n);
        int a, b;
        printf("Enter two indices to reveal the elements: ");
        scanf("%d %d", &a, &b);
        if(a<0 || a>=n || b<0 || b>=n || temp[a]!=0 || temp[b]!=0){
            printf("Invalid index(es)! Try again.\n");
            continue;
        }
        if(arr[a] == arr[b]){
            temp[a] = temp[b] = arr[a];
            count++;
            if(count == n/2){
                printf("Congratulations! You have completed the game.\n");
                break;
            }
        }
        else{
            printf("Oops! Wrong match.\n");
        }
    }
}

int main(){
    printf("Welcome to the Memory Game.\n");
    printf("Rules of the game: You will be given a list of hidden numbers.\n");
    printf("The numbers will be hidden behind blanks.\n");
    printf("You will be asked to choose two indices to reveal the hidden numbers.\n");
    printf("If the numbers match, they will be revealed permanently.\n");
    printf("If they do not match, they will be hidden again and you can try again.\n");
    printf("The game will end once you have revealed all the numbers permanently.\n");
    printf("Let's get started.\n");
    play_game();
    return 0;
}