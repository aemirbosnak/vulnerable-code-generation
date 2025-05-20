//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: Alan Turing
#define MAX_RECORDS 100
#define TABLE_SIZE 101

typedef struct {
    int key;
    char name[30];
    float value;
} Record;

Record database[MAX_RECORDS];
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insertRecord(int key, char name[], float value) {
    int index = hashFunction(key);
    if (database[index].key == -1) {
        strcpy(database[index].name, name);
        database[index].key = key;
        database[index].value = value;
    } else {
        int i = index;
        while (database[i].key != -1 && database[i].key != key) {
            i++;
        }
        if (i >= TABLE_SIZE) {
            printf("Table is full.\n");
            return;
        }
        strcpy(database[i].name, name);
        database[i].key = key;
        database[i].value = value;
    }
}

void searchRecord(int key) {
    int index = hashFunction(key);
    if (database[index].key == -1) {
        printf("Record not found.\n");
        return;
    }
    int i = index;
    while (database[i].key != key) {
        i++;
    }
    printf("Key: %d, Name: %s, Value: %.2f\n", database[i].key, database[i].name, database[i].value);
}

void deleteRecord(int key) {
    int index = hashFunction(key);
    if (database[index].key == -1) {
        printf("Record not found.\n");
        return;
    }
    int i = index;
    while (database[i].key != key) {
        i++;
    }
    database[i].key = -1;
}

void initializeDatabase() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        database[i].key = -1;
    }
}

int main() {
    initializeDatabase();
    insertRecord(1, "John Doe", 30.5);
    insertRecord(2, "Jane Doe", 25.6);
    insertRecord(1, "John Doe", 31.5); // Overwriting the previous record with the same key
    searchRecord(1);
    searchRecord(3);
    deleteRecord(1);
    searchRecord(1);
    return 0;
}