//FormAI DATASET v1.0 Category: Database Indexing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// struct to hold data
struct Data {
    int id;
    char name[20];
};

// struct to hold indexed data
struct Index {
    int key;
    int offset;
};

// function to read data from file
struct Data* read_data(FILE* fp, int* n) {
    // get number of records
    fread(n, sizeof(int), 1, fp);
    // allocate memory for data
    struct Data* data = (struct Data*) malloc(sizeof(struct Data) * (*n));
    // read data from file
    fread(data, sizeof(struct Data), (*n), fp);
    return data;
}

// function to write indexed data to file
void write_index(FILE* fp, struct Index* index, int n) {
    // write number of records
    fwrite(&n, sizeof(int), 1, fp);
    // write index to file
    fwrite(index, sizeof(struct Index), n, fp);
}

// function to sort data based on id
void sort_data(struct Data* data, int n) {
    int i, j;
    struct Data temp;
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(data[i].id > data[j].id) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

// function to create index and return it
struct Index* create_index(struct Data* data, int n) {
    // allocate memory for index
    struct Index* index = (struct Index*) malloc(sizeof(struct Index) * n);
    // fill index with data
    int i;
    for(i=0; i<n; i++) {
        index[i].key = data[i].id;
        index[i].offset = i;
    }
    return index;
}

// function to search data based on id
void search_data(struct Data* data, struct Index* index, int n, int id) {
    int i, index_pos, data_pos;
    // binary search for id in index
    int low = 0, high = n-1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(index[mid].key == id) {
            index_pos = mid;
            break;
        }
        else if(index[mid].key < id)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if(low > high) {
        printf("Record with id %d not found!\n", id);
        return;
    }
    // get data offset from index
    data_pos = index[index_pos].offset;
    // print data
    printf("Record with id %d found!\n", id);
    printf("ID: %d\nName: %s\n", data[data_pos].id, data[data_pos].name);
}

int main() {
    int n;
    FILE* data_file = fopen("data.bin", "rb");
    if(data_file == NULL) {
        printf("File not found!\n");
        return 0;
    }

    // read data from file
    struct Data* data = read_data(data_file, &n);
    fclose(data_file);

    // sort data based on id
    sort_data(data, n);

    // create index for data
    struct Index* index = create_index(data, n);

    // write index to file
    FILE* index_file = fopen("index.bin", "wb");
    write_index(index_file, index, n);
    fclose(index_file);

    // search data based on id
    int id;
    printf("Enter id to search: ");
    scanf("%d", &id);
    search_data(data, index, n, id);

    // free memory
    free(data);
    free(index);

    return 0;
}