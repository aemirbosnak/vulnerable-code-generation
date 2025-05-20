//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 1024
#define BLOCKS_PER_TRACK 1000
#define NUM_TRACKS 50

typedef struct {
    char bytes[BLOCK_SIZE];
} Block;

Block disk[NUM_TRACKS][BLOCKS_PER_TRACK];

void recover_data(int start_track, int start_block, int end_track, int end_block) {
    FILE *fp;
    char file_name[20];
    sprintf(file_name, "recovered_data_%d_%d_%d_%d.txt", start_track, start_block, end_track, end_block);
    fp = fopen(file_name, "w");

    for(int i = start_track; i <= end_track; i++) {
        for(int j = start_block; j <= end_block; j++) {
            fwrite(disk[i][j].bytes, sizeof(char), BLOCK_SIZE, fp);
        }
    }
    
    fclose(fp);
}

int main() {
    int n;
    char option[10];

    printf("Enter the number of blocks with lost data: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int track, block;
        printf("Enter the track and block number of lost block %d: ", i+1);
        scanf("%d %d", &track, &block);
        printf("Enter the data for block %d: ", i+1);
        scanf("%s", disk[track][block].bytes);
    }

    printf("Data recovery tool:\n");
    printf("Enter the start track (between 0 and 49): ");
    int start_track, start_block;
    scanf("%d", &start_track);
    printf("Enter the start block (between 0 and 999): ");
    scanf("%d", &start_block);
    printf("Enter the end track (between %d and 49): ", start_track);
    int end_track, end_block;
    scanf("%d", &end_track);
    printf("Enter the end block (between %d and 999): ", (end_track == start_track ? start_block : 0));
    scanf("%d", &end_block);

    recover_data(start_track, start_block, end_track, end_block);

    printf("Data recovered successfully!\n");
    
    return 0;
}