//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_DATA 10000
#define NUM_DATA 10

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int sighting_duration;
    int num_ufos;
    int num_witnesses;
    float credibility_rating;
    char location[50];
} SightingData;

void read_data(SightingData data[], int num_data) {
    FILE *fp = fopen("sighting_data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < num_data; i++) {
        fscanf(fp, "%d-%d-%d %d:%d:%d %d %d %f %s\n", &data[i].year, &data[i].month, &data[i].day, &data[i].hour, &data[i].minute, &data[i].second, &data[i].sighting_duration, &data[i].num_ufos, &data[i].num_witnesses, &data[i].credibility_rating);
        fscanf(fp, "%s\n", data[i].location);
    }

    fclose(fp);
}

void calculate_probability(SightingData data[], int num_data) {
    int total_ufos = 0;
    int total_witnesses = 0;
    float total_credibility_rating = 0.0;

    for (int i = 0; i < num_data; i++) {
        total_ufos += data[i].num_ufos;
        total_witnesses += data[i].num_witnesses;
        total_credibility_rating += data[i].credibility_rating;
    }

    float average_credibility_rating = total_credibility_rating / num_data;
    float probability = (float)total_ufos / (float)total_witnesses * average_credibility_rating;

    printf("Probability of alien invasion: %.2f%%\n", probability * 100.0);
}

int main() {
    SightingData data[MAX_DATA];
    int num_data = 0;

    read_data(data, MAX_DATA);
    num_data = NUM_DATA;

    calculate_probability(data, num_data);

    return 0;
}