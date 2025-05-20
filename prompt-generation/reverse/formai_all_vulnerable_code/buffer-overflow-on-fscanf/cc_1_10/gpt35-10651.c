//FormAI DATASET v1.0 Category: Data recovery tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read in the block pointer file
    FILE *fp = fopen("block_pointers.txt", "r");
    
    if (!fp) {
        printf("Error: Could not open block pointer file\n");
        return -1;
    }
    
    int num_blocks;
    fscanf(fp, "%d", &num_blocks);
    
    // Create an array to store block pointers
    int *block_ptrs = (int *) malloc(num_blocks * sizeof(int));
    int i;
    
    for (i = 0; i < num_blocks; i++) {
        fscanf(fp, "%d", &block_ptrs[i]);
    }
    
    fclose(fp);
    
    // Recover the file
    FILE *file_out = fopen("recovered_data.txt", "w");
    
    if (!file_out) {
        printf("Error: Could not open output file\n");
        return -1;
    }
    
    int curr_block = 0;
    int next_block = block_ptrs[curr_block];
    int data;
    
    while (next_block != -1) {
        // Read in the block data
        FILE *block_in = fopen("block_files/block" + next_block, "r");
        
        if (!block_in) {
            printf("Error: Could not open block file\n");
            return -1;
        }
        
        while (fscanf(block_in, "%d", &data) != EOF) {
            fprintf(file_out, "%d\n", data);
        }
        
        fclose(block_in);
        curr_block++;
        next_block = block_ptrs[curr_block];
    }
    
    fclose(file_out);
    
    printf("File recovered successfully!\n");
    
    free(block_ptrs);
    
    return 0;
}