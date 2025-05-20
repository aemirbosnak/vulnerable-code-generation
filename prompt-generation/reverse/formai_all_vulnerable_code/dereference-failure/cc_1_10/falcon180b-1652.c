//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 10
#define MAX_FEATURES 1000
#define MAX_SAMPLES 10000

typedef struct {
    int id;
    char name[64];
} class_t;

typedef struct {
    int id;
    char name[64];
    double value;
} feature_t;

typedef struct {
    int id;
    int class_id;
    feature_t *features;
} sample_t;

class_t *classes;
int num_classes;

feature_t *features;
int num_features;

sample_t *samples;
int num_samples;

void init() {
    classes = (class_t *) malloc(MAX_CLASSES * sizeof(class_t));
    num_classes = 0;

    features = (feature_t *) malloc(MAX_FEATURES * sizeof(feature_t));
    num_features = 0;

    samples = (sample_t *) malloc(MAX_SAMPLES * sizeof(sample_t));
    num_samples = 0;
}

void add_class(char *name) {
    class_t *c = &classes[num_classes];
    strcpy(c->name, name);
    c->id = num_classes++;
}

void add_feature(char *name, double value) {
    feature_t *f = &features[num_features];
    strcpy(f->name, name);
    f->value = value;
    f->id = num_features++;
}

void add_sample(int class_id, int num_features, feature_t *features) {
    sample_t *s = &samples[num_samples];
    s->class_id = class_id;
    s->features = features;
    num_samples++;
}

int main() {
    init();

    add_class("Animal");
    add_class("Plant");

    add_feature("Number of Legs", 4);
    add_feature("Has Fur", 1);
    add_feature("Number of Leaves", 3);

    add_sample(0, 2, features);
    add_sample(1, 2, features + 2);

    return 0;
}