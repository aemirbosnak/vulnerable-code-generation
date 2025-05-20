//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

int create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS leaderboard ("
                      "name TEXT PRIMARY KEY NOT NULL,"
                      "score INTEGER NOT NULL);";
    char *errMsg = 0;
    return sqlite3_exec(db, sql, 0, 0, &errMsg);
}

int add_player_score(sqlite3 *db, const char *name, int score) {
    char sql[100];
    snprintf(sql, 100, "INSERT INTO leaderboard (name, score) VALUES ('%s', %d);", name, score);
    char *errMsg = 0;
    return sqlite3_exec(db, sql, 0, 0, &errMsg);
}

int update_player_score(sqlite3 *db, const char *name, int score) {
    char sql[100];
    snprintf(sql, 100, "UPDATE leaderboard SET score = %d WHERE name = '%s';", score, name);
    char *errMsg = 0;
    return sqlite3_exec(db, sql, 0, 0, &errMsg);
}

int fetch_leaderboard(sqlite3 *db) {
    const char *sql = "SELECT * FROM leaderboard ORDER BY score DESC;";
    sqlite3_stmt *stmt;
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        printf("Failed to fetch leaderboard: %s\n", sqlite3_errmsg(db));
        return -1;
    }

    printf("Leaderboard:\n");
    printf("Name\tScore\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char *name = (const char *)sqlite3_column_text(stmt, 0);
        int score = sqlite3_column_int(stmt, 1);
        printf("%s\t%d\n", name, score);
    }
    
    sqlite3_finalize(stmt);
    return 0;
}

int main() {
    sqlite3 *db;
    if (sqlite3_open("game.db", &db)) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    if (create_table(db) != SQLITE_OK) {
        fprintf(stderr, "Can't create table: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    Player players[MAX_PLAYERS];
    int player_count = 0;
    char command[10];

    while (1) {
        printf("Enter command (register, score, leaderboard, exit): ");
        scanf("%s", command);

        if (strcmp(command, "register") == 0) {
            if (player_count >= MAX_PLAYERS) {
                printf("Maximum players reached!\n");
                continue;
            }
            printf("Enter player name: ");
            scanf("%s", players[player_count].name);
            players[player_count].score = 0; // Initial score set to 0
            add_player_score(db, players[player_count].name, players[player_count].score);
            player_count++;
            printf("Player registered!\n");
        } else if (strcmp(command, "score") == 0) {
            char name[MAX_NAME_LENGTH];
            int score;
            printf("Enter player name: ");
            scanf("%s", name);
            printf("Enter new score: ");
            scanf("%d", &score);
            update_player_score(db, name, score);
            printf("Score updated!\n");
        } else if (strcmp(command, "leaderboard") == 0) {
            fetch_leaderboard(db);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    sqlite3_close(db);
    return 0;
}