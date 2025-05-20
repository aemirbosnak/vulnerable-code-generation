#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <stdint.h>

typedef struct {
    char path[256];
    uintmax_t total, used, avail, pct;
} PathStats;

void get_stats(const char *path, PathStats *stats) {
    struct statvfs st;
    if (statvfs(path, &st) == -1) {
        fprintf(stderr, "Error: cannot stat '%s'\n", path);
        stats->total = stats->used = stats->avail = stats->pct = 0;
        return;
    }

    stats->total = (uintmax_t)st.f_blocks * (uintmax_t)st.f_frsize;
    stats->used = (uintmax_t)st.f_blocks * (uintmax_t)st.f_frsize - stats->avail * (uintmax_t)st.f_frsize;
    stats->avail = st.f_bavail * st.f_frsize;
    stats->pct = (stats->used * 100) / stats->total;
}

void print_stats(const PathStats *stats) {
    printf("%s: Total: %" PRIuMAX " bytes, Used: %" PRIuMAX " bytes (%.2f%%)\n",
           stats->path, stats->total, stats->used, stats->pct / 100.0);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    PathStats stats;
    get_stats(argv[1], &stats);
    print_stats(&stats);

    return 0;
}
