//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main(){
    int signal_strength[10];
    int i, j, min_index, temp;
    
    printf("Enter the signal strength values for 10 Wi-Fi networks (0-100):\n");
    
    // input of signal strength values
    for(i=0; i<10; i++){
        printf("Network %d: ", i+1);
        scanf("%d", &signal_strength[i]);
    }
    
    printf("\nOriginal Signal Strengths:\n");
    
    // display original signal strength values
    for(i=0; i<10; i++){
        printf("Network %d: %d\n", i+1, signal_strength[i]);
    }
    
    // sorting of signal strength values in ascending order
    for(i=0; i<9; i++){
        min_index = i;
        for(j=i+1; j<10; j++){
            if(signal_strength[j] < signal_strength[min_index]){
                min_index = j;
            }
        }
        temp = signal_strength[i];
        signal_strength[i] = signal_strength[min_index];
        signal_strength[min_index] = temp;
    }
    
    printf("\nSorted Signal Strengths:\n");
    
    // display sorted signal strength values
    for(i=0; i<10; i++){
        printf("Network %d: %d\n", i+1, signal_strength[i]);
    }
    
    // puzzling part
    int max_strength_index, min_strength_index;
    max_strength_index = 9;
    min_strength_index = 0;
    
    while(min_strength_index < max_strength_index){
        printf("\nCurrent strongest network: %d\nCurrent weakest network: %d\n", signal_strength[max_strength_index], signal_strength[min_strength_index]);
        max_strength_index--;
        min_strength_index++;
    }
    
    return 0;
}