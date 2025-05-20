//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: configurable
// Percolation Simulator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // number of sites
#define T 10000 // number of trials

// site struct
typedef struct {
    int x; // x-coordinate
    int y; // y-coordinate
    int status; // open (0) or closed (1)
} Site;

// generate random site
Site generate_site(int x, int y) {
    Site site;
    site.x = x;
    site.y = y;
    site.status = rand() % 2; // 0 or 1
    return site;
}

// open site
void open_site(Site *site) {
    site->status = 1;
}

// is site open?
int is_open(Site *site) {
    return site->status == 1;
}

// is site closed?
int is_closed(Site *site) {
    return site->status == 0;
}

// is site connected to top?
int is_connected_to_top(Site *site) {
    return site->y == 0;
}

// is site connected to bottom?
int is_connected_to_bottom(Site *site) {
    return site->y == N - 1;
}

// is site connected to left?
int is_connected_to_left(Site *site) {
    return site->x == 0;
}

// is site connected to right?
int is_connected_to_right(Site *site) {
    return site->x == N - 1;
}

// is site connected to top, bottom, left, or right?
int is_connected(Site *site) {
    return is_connected_to_top(site) || is_connected_to_bottom(site) || is_connected_to_left(site) || is_connected_to_right(site);
}

// check if site is open and connected
int is_open_and_connected(Site *site) {
    return is_open(site) && is_connected(site);
}

// check if site is open and not connected
int is_open_and_not_connected(Site *site) {
    return is_open(site) && !is_connected(site);
}

// check if site is closed and connected
int is_closed_and_connected(Site *site) {
    return is_closed(site) && is_connected(site);
}

// check if site is closed and not connected
int is_closed_and_not_connected(Site *site) {
    return is_closed(site) && !is_connected(site);
}

// check if site is open and connected to top, bottom, left, or right
int is_open_and_connected_to_edge(Site *site) {
    return is_open(site) && is_connected_to_top(site) || is_connected_to_bottom(site) || is_connected_to_left(site) || is_connected_to_right(site);
}

// check if site is closed and connected to top, bottom, left, or right
int is_closed_and_connected_to_edge(Site *site) {
    return is_closed(site) && is_connected_to_top(site) || is_connected_to_bottom(site) || is_connected_to_left(site) || is_connected_to_right(site);
}

// run trial
void run_trial(Site *sites) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (rand() % 2 == 0) {
                open_site(&sites[i * N + j]);
            }
        }
    }
}

// check if percolation occurs
int check_percolation(Site *sites) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (is_open_and_connected(&sites[i * N + j])) {
                return 1;
            }
        }
    }
    return 0;
}

// print results
void print_results(Site *sites, int trials) {
    int i, j, count = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (is_open_and_connected(&sites[i * N + j])) {
                count++;
            }
        }
    }
    printf("Percentage of open sites connected to top, bottom, left, or right: %f%%\n", (float)count / (N * N) * 100);
}

int main() {
    Site *sites = (Site *)malloc(N * N * sizeof(Site));
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            sites[i * N + j] = generate_site(i, j);
        }
    }
    int trials = 0;
    while (trials < T) {
        run_trial(sites);
        trials++;
        if (check_percolation(sites)) {
            break;
        }
    }
    print_results(sites, trials);
    return 0;
}