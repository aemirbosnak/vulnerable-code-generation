//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DATA_SIZE 100
#define MAX_INDEX_SIZE 10

typedef struct {
    char data[MAX_DATA_SIZE];
    char index[MAX_INDEX_SIZE];
} Index;

int main() {
    Index indexes[MAX_INDEX_SIZE];
    
    // Initialize indexes array
    for (int i = 0; i < MAX_INDEX_SIZE; i++) {
        indexes[i].data[0] = 'A';
        indexes[i].data[1] = 'B';
        indexes[i].data[2] = 'C';
        indexes[i].data[3] = 'D';
        indexes[i].data[4] = 'E';
        indexes[i].data[5] = 'F';
        indexes[i].data[6] = 'G';
        indexes[i].data[7] = 'H';
        indexes[i].data[8] = 'I';
        indexes[i].data[9] = 'J';
        indexes[i].data[10] = 'K';
        indexes[i].data[11] = 'L';
        indexes[i].data[12] = 'M';
        indexes[i].data[13] = 'N';
        indexes[i].data[14] = 'O';
        indexes[i].data[15] = 'P';
        indexes[i].data[16] = 'Q';
        indexes[i].data[17] = 'R';
        indexes[i].data[18] = 'S';
        indexes[i].data[19] = 'T';
        indexes[i].data[20] = 'U';
        indexes[i].data[21] = 'V';
        indexes[i].data[22] = 'W';
        indexes[i].data[23] = 'X';
        indexes[i].data[24] = 'Y';
        indexes[i].data[25] = 'Z';
        indexes[i].data[26] = '\0';

        indexes[i].index[0] = 'A';
        indexes[i].index[1] = 'B';
        indexes[i].index[2] = 'C';
        indexes[i].index[3] = 'D';
        indexes[i].index[4] = 'E';
        indexes[i].index[5] = 'F';
        indexes[i].index[6] = 'G';
        indexes[i].index[7] = 'H';
        indexes[i].index[8] = 'I';
        indexes[i].index[9] = 'J';
        indexes[i].index[10] = 'K';
        indexes[i].index[11] = 'L';
        indexes[i].index[12] = 'M';
        indexes[i].index[13] = 'N';
        indexes[i].index[14] = 'O';
        indexes[i].index[15] = 'P';
        indexes[i].index[16] = 'Q';
        indexes[i].index[17] = 'R';
        indexes[i].index[18] = 'S';
        indexes[i].index[19] = 'T';
        indexes[i].index[20] = 'U';
        indexes[i].index[21] = 'V';
        indexes[i].index[22] = 'W';
        indexes[i].index[23] = 'X';
        indexes[i].index[24] = 'Y';
        indexes[i].index[25] = 'Z';
        indexes[i].index[26] = '\0';
    }
    
    // Print indexes
    for (int i = 0; i < MAX_INDEX_SIZE; i++) {
        printf("Index %d:\n", i);
        printf("Data: %s\n", indexes[i].data);
        printf("Index: %s\n", indexes[i].index);
        printf("\n");
    }
    
    return 0;
}