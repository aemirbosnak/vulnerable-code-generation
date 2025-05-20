//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SAMPLES 1000
#define MAX_BINS 20

struct sample {
    double value;
    int count;
};

struct histogram {
    int num_bins;
    double min_value;
    double max_value;
    double bin_width;
    struct sample *bins;
};

struct histogram *create_histogram(double min_value, double max_value, int num_bins) {
    struct histogram *hist = malloc(sizeof(struct histogram));
    hist->num_bins = num_bins;
    hist->min_value = min_value;
    hist->max_value = max_value;
    hist->bin_width = (max_value - min_value) / num_bins;
    hist->bins = malloc(sizeof(struct sample) * num_bins);
    for (int i = 0; i < num_bins; i++) {
        hist->bins[i].value = min_value + i * hist->bin_width;
        hist->bins[i].count = 0;
    }
    return hist;
}

void add_sample(struct histogram *hist, double value) {
    int bin_index = (int)((value - hist->min_value) / hist->bin_width);
    hist->bins[bin_index].count++;
}

void print_histogram(struct histogram *hist) {
    for (int i = 0; i < hist->num_bins; i++) {
        printf("%f - %f: %d\n", hist->bins[i].value, hist->bins[i].value + hist->bin_width, hist->bins[i].count);
    }
}

int main() {
    double data[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0};
    int num_samples = sizeof(data) / sizeof(data[0]);
    struct histogram *hist = create_histogram(1.0, 10.0, 5);
    for (int i = 0; i < num_samples; i++) {
        add_sample(hist, data[i]);
    }
    print_histogram(hist);
    free(hist->bins);
    free(hist);
    return 0;
}