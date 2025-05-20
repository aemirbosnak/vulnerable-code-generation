//FormAI DATASET v1.0 Category: Database Indexing System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Structure to represent the keys and their positions in the primary file*/
typedef struct key_pos {
    int key;
    long position;
} key_pos;

/* Function to compare the keys for qsort*/
int compare_keys(const void* a, const void* b) {
    return ((key_pos*)a)->key - ((key_pos*)b)->key;
}

/* Function to read the primary file and create the index file*/
void create_index_file(char* primary_file_name, char* index_file_name) {
    int i, key_count = 0;
    FILE* primary_file = fopen(primary_file_name, "r");
    FILE* index_file = fopen(index_file_name, "wb");

    /* Count the number of keys in the primary file*/
    while(!feof(primary_file)) {
        int key;
        fscanf(primary_file, "%d", &key);
        key_count++;
    }

    /* Create an array of key_pos structures and read the keys and their positions*/
    key_pos* arr = (key_pos*)malloc(key_count*sizeof(key_pos));
    fseek(primary_file, 0, SEEK_SET);
    for(i=0; i<key_count; i++) {
        arr[i].position = ftell(primary_file);
        fscanf(primary_file, "%d", &arr[i].key);
    }

    /* Sort the array of keys*/
    qsort(arr, key_count, sizeof(key_pos), compare_keys);

    /* Write the sorted keys and their positions to the index file*/
    for(i=0; i<key_count; i++) {
        fwrite(&arr[i], sizeof(key_pos), 1, index_file);
    }

    /* Clean up*/
    free(arr);
    fclose(primary_file);
    fclose(index_file);
}

/* Function to search for a given key in the index file*/
long search_key(int key, char* index_file_name) {
    int i, key_count;
    FILE* index_file = fopen(index_file_name, "rb");

    /* Count the number of keys in the index file*/
    fseek(index_file, 0, SEEK_END);
    key_count = ftell(index_file)/sizeof(key_pos);
    fseek(index_file, 0, SEEK_SET);

    /* Binary search for the key*/
    int low = 0, high = key_count-1;
    while(low<=high) {
        int mid = (low+high)/2;
        key_pos kp;
        fseek(index_file, mid*sizeof(key_pos), SEEK_SET);
        fread(&kp, sizeof(key_pos), 1, index_file);
        if(kp.key == key) {
            /* Key found, return its position*/
            fclose(index_file);
            return kp.position;
        }
        else if(kp.key < key) {
            /* Key is in the upper half*/
            low = mid+1;
        }
        else {
            /* Key is in the lower half*/
            high = mid-1;
        }
    }

    /* Key not found*/
    fclose(index_file);
    return -1;
}

/* Main function*/
int main() {
    /* Create the index file*/
    create_index_file("primary_file.txt", "index_file.bin");

    /* Search for a key in the index file*/
    long position = search_key(42, "index_file.bin");
    if(position == -1) {
        printf("Key not found\n");
    }
    else {
        /* Open the primary file and go to the position of the key*/
        FILE* primary_file = fopen("primary_file.txt", "r");
        fseek(primary_file, position, SEEK_SET);

        /* Print the key*/
        int key;
        fscanf(primary_file, "%d", &key);
        printf("Key found at position %ld: %d\n", position, key);

        /* Clean up*/
        fclose(primary_file);
    }

    return 0;
}