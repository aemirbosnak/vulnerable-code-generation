//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

struct csv_data {
    char **rows;
    int num_rows;
    int num_cols;
};

void *load_csv_file(void *arg) {
    FILE *fp = (FILE *) arg;
    char line[1024];
    char delimiter = ',';
    struct csv_data *data = malloc(sizeof(struct csv_data));

    data->num_rows = 0;
    data->num_cols = 0;
    data->rows = malloc(MAX_ROWS * sizeof(char *));

    while (fgets(line, 1024, fp)!= NULL) {
        char *token = strtok(line, &delimiter);

        if (data->num_cols == 0) {
            while (token!= NULL) {
                data->num_cols++;
                token = strtok(NULL, &delimiter);
            }
        }

        data->rows[data->num_rows] = malloc((data->num_cols + 1) * sizeof(char));
        strcpy(data->rows[data->num_rows], line);
        data->num_rows++;
    }

    return data;
}

void print_csv_data(struct csv_data *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            printf("%s ", data->rows[i]);
        }
        printf("\n");
    }
}

int main() {
    pthread_t thread_id;
    FILE *fp = fopen("example.csv", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    pthread_create(&thread_id, NULL, load_csv_file, (void *) fp);
    pthread_join(thread_id, NULL);

    struct csv_data *data = (struct csv_data *) malloc(sizeof(struct csv_data));
    data = (struct csv_data *) load_csv_file((void *) fp);

    print_csv_data(data);

    free(data->rows);
    free(data);

    fclose(fp);
    return 0;
}