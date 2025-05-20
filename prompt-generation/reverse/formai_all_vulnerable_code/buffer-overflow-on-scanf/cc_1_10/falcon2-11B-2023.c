//Falcon2-11B DATASET v1.0 Category: URL Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize_url(char *url) {
    char *scheme = strstr(url, "://");
    if (scheme!= NULL) {
        scheme += 3;
        int scheme_len = strlen(scheme);
        int scheme_idx = 0;
        while (scheme[scheme_len - 1 - scheme_idx]!= ':') {
            scheme_idx++;
        }
        scheme[scheme_len - scheme_idx] = '\0';
        strcpy(scheme, scheme + scheme_idx + 1);
        url = scheme;
    }

    char *host = strstr(url, "/");
    if (host!= NULL) {
        host += 1;
        int host_len = strlen(host);
        int host_idx = 0;
        while (host[host_len - 1 - host_idx]!= '/') {
            host_idx++;
        }
        host[host_len - host_idx] = '\0';
        strcpy(host, host + host_idx + 1);
        url = host;
    }

    char *path = strstr(url, "/");
    if (path!= NULL) {
        path += 1;
        int path_len = strlen(path);
        int path_idx = 0;
        while (path[path_len - 1 - path_idx]!= '/') {
            path_idx++;
        }
        path[path_len - path_idx] = '\0';
        strcpy(path, path + path_idx + 1);
        url = path;
    }

    char *query = strstr(url, "?");
    if (query!= NULL) {
        query += 1;
        int query_len = strlen(query);
        int query_idx = 0;
        while (query[query_len - 1 - query_idx]!= '?') {
            query_idx++;
        }
        query[query_len - query_idx] = '\0';
        strcpy(query, query + query_idx + 1);
        url = query;
    }

    char *fragment = strstr(url, "#");
    if (fragment!= NULL) {
        fragment += 1;
        int fragment_len = strlen(fragment);
        int fragment_idx = 0;
        while (fragment[fragment_len - 1 - fragment_idx]!= '#') {
            fragment_idx++;
        }
        fragment[fragment_len - fragment_idx] = '\0';
        strcpy(fragment, fragment + fragment_idx + 1);
        url = fragment;
    }

    printf("Sanitized URL: %s\n", url);
}

int main() {
    char url[100];
    printf("Enter a URL: ");
    scanf("%s", url);
    sanitize_url(url);
    return 0;
}