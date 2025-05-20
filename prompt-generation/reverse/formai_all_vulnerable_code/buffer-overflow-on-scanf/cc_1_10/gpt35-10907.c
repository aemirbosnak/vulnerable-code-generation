//FormAI DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100 // maximum number of records
#define KEY_LEN 10 // maximum length of key field

// structure to represent each record
typedef struct record{
    char key[KEY_LEN];
    char data[100];
} Record;

// structure to represent the index table
typedef struct index{
    char key[KEY_LEN];
    int rec_num;
} Index;

int main(){
    Record records[SIZE]; // database records
    Index index_table[SIZE]; // index table
    int num_recs = 0; // number of records in database
    int num_idx = 0; // number of entries in index table
    
    // populate database records
    strcpy(records[0].key, "abc");
    strcpy(records[0].data, "Record 0 data");
    num_recs++;
    
    strcpy(records[1].key, "def");
    strcpy(records[1].data, "Record 1 data");
    num_recs++;
    
    strcpy(records[2].key, "ghi");
    strcpy(records[2].data, "Record 2 data");
    num_recs++;
    
    // populate index table
    for(int i=0;i<num_recs;i++){
        strcpy(index_table[i].key, records[i].key);
        index_table[i].rec_num = i;
        num_idx++;
    }
    
    // search for a record based on key value
    printf("Enter key value to search: ");
    char search_key[KEY_LEN];
    scanf("%s", search_key);
    
    int found = 0;
    for(int i=0;i<num_idx;i++){
        if(strcmp(index_table[i].key, search_key) == 0){
            found = 1;
            int rec_num = index_table[i].rec_num;
            printf("Record found!\n");
            printf("Key: %s\n", records[rec_num].key);
            printf("Data: %s\n", records[rec_num].data);
            break;
        }
    }
    
    if(!found){
        printf("Record not found!\n");
    }
    
    return 0;
}