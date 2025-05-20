//FormAI DATASET v1.0 Category: Computer Biology ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*A program that reads DNA sequences and outputs the total number of guanine-cytosine (GC) base pairs in each sequence*/

int main(){

    char** sequences;   /*2D array to store the DNA sequences*/
    int* gc_content;    /*array to hold the GC content for each sequence*/
    int n, m, i, j, gc_count;   /*variables for loop counters, sequence lengths, and GC content*/

    printf("Enter the number of DNA sequences: ");
    scanf("%d", &n);

    /*allocate memory for sequences array*/
    sequences = (char**)malloc(n*sizeof(char*));
    for(i=0; i<n; i++){
        sequences[i] = (char*)malloc(100*sizeof(char));  /*assuming each sequence will be at most 100 base pairs*/
    }

    /*read in the DNA sequences*/
    for(i=0; i<n; i++){
        printf("Enter sequence %d: ", i+1);
        scanf("%s", sequences[i]);
    }

    /*allocate memory for gc_content array*/
    gc_content = (int*)malloc(n*sizeof(int));

    /*calculate gc content for each sequence*/
    for(i=0; i<n; i++){
        m = strlen(sequences[i]);   /*get length of sequence*/
        gc_count = 0;
        for(j=0; j<m; j++){
            if(sequences[i][j] == 'G' || sequences[i][j] == 'C'){
                gc_count++;
            }
        }
        gc_content[i] = (gc_count * 100) / m;   /*calculate GC percentage*/
    }

    /*output gc_content for each sequence*/
    printf("GC Content:\n");
    for(i=0; i<n; i++){
        printf("Sequence %d: %d%%\n", i+1, gc_content[i]);
    }

    /*free memory*/
    for(i=0; i<n; i++){
        free(sequences[i]);
    }
    free(sequences);
    free(gc_content);

    return 0;
}