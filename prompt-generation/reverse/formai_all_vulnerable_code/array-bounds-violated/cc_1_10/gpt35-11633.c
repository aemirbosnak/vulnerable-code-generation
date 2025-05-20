//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Distributed C Checksum Calculator
#define CHUNK_SIZE 512 // size of chunks to process
#define MAX_NUM_CHUNKS 1024 // max number of chunks to process
#define NUM_THREADS 4 // number of threads to use for processing

typedef unsigned short uint16;
typedef unsigned int uint32;

// function to calculate checksum of a chunk
uint16 checksum(uint16 *data, uint32 size) {
    uint32 checksum = 0;
    for (uint32 i = 0; i < size; i++) {
        checksum += data[i];
    }
    return (uint16)(checksum & 0xFFFF) + (uint16)(checksum >> 16);
}

// worker function to process a chunk
void worker(uint16 *data, uint32 size, uint16 *results, uint32 index) {
    uint16 cksum = checksum(data, size);
    results[index] = cksum;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // read in file
    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("Error: could not open file\n");
        return 1;
    }

    // calculate file size and number of chunks to process
    fseek(fp, 0L, SEEK_END);
    uint32 filesize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    uint32 num_chunks = filesize / CHUNK_SIZE;
    if (filesize % CHUNK_SIZE != 0) {
        num_chunks++;
    }
    if (num_chunks > MAX_NUM_CHUNKS) {
        num_chunks = MAX_NUM_CHUNKS;
    }

    // allocate memory for chunks and results
    uint16 *chunks[num_chunks];
    uint16 results[num_chunks];
    for (uint32 i = 0; i < num_chunks; i++) {
        chunks[i] = malloc(sizeof(uint16) * CHUNK_SIZE);
        results[i] = 0;
    }

    // read in chunks
    for (uint32 i = 0; i < num_chunks; i++) {
        fread(chunks[i], sizeof(uint16), CHUNK_SIZE, fp);
    }

    // create worker threads
    uint32 chunk_size = filesize / NUM_THREADS;
    if (filesize % NUM_THREADS != 0) {
        chunk_size++;
    }
    uint32 start = 0;
    uint32 end = 0;
    for (uint32 i = 0; i < NUM_THREADS; i++) {
        end = start + chunk_size;
        if (end > filesize) {
            end = filesize;
        }
        uint32 chunk_index = i % num_chunks;
        worker(chunks[chunk_index] + start / sizeof(uint16),
               (end - start) / sizeof(uint16),
               results, chunk_index);
        start = end;
    }

    // calculate final checksum
    uint16 final_checksum = checksum(results, num_chunks);
    printf("Checksum: 0x%04X\n", final_checksum);

    // free memory
    for (uint32 i = 0; i < num_chunks; i++) {
        free(chunks[i]);
    }

    return 0;
}