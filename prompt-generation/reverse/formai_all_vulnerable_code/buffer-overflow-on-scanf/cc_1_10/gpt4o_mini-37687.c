//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_PLAYERS 10
#define DB_NAME "game_sessions.db"

typedef struct {
    int id;
    char name[50];
    int score;
} Player;

typedef struct {
    int id;
    char title[50];
    int player_count;
    Player players[MAX_PLAYERS];
} GameSession;

int create_game_session(sqlite3 *db, const char *title) {
    char *err_msg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO sessions(title) VALUES('%s');", title);
    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return -1;
    }
    return 0;
}

int join_game_session(sqlite3 *db, int session_id, const char *player_name) {
    char *err_msg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO players(session_id, name, score) VALUES(%d, '%s', 0);", session_id, player_name);
    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return -1;
    }
    return 0;
}

void display_scores(sqlite3 *db, int session_id) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT name, score FROM players WHERE session_id = ?;";
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }
    
    sqlite3_bind_int(stmt, 1, session_id);
    
    printf("Scores:\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char *name = (const char *)sqlite3_column_text(stmt, 0);
        int score = sqlite3_column_int(stmt, 1);
        printf("%s: %d\n", name, score);
    }
    
    sqlite3_finalize(stmt);
}

void display_sessions(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT id, title FROM sessions;";
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }
    
    printf("Available Game Sessions:\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *title = (const char *)sqlite3_column_text(stmt, 1);
        printf("Session ID: %d, Title: %s\n", id, title);
    }
    
    sqlite3_finalize(stmt);
}

int main() {
    sqlite3 *db;
    char *err_msg = 0;
    
    if (sqlite3_open(DB_NAME, &db) != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    
    char *create_sessions_sql = "CREATE TABLE IF NOT EXISTS sessions(id INTEGER PRIMARY KEY, title TEXT);";
    char *create_players_sql = "CREATE TABLE IF NOT EXISTS players(id INTEGER PRIMARY KEY, session_id INTEGER, name TEXT, score INTEGER, FOREIGN KEY(session_id) REFERENCES sessions(id));";
    
    sqlite3_exec(db, create_sessions_sql, 0, 0, &err_msg);
    sqlite3_exec(db, create_players_sql, 0, 0, &err_msg);
    
    int choice, session_id;
    char player_name[50], session_title[50];

    while (1) {
        printf("\nMenu:\n1. Create Game Session\n2. Join Game Session\n3. Display Game Sessions\n4. Display Scores\n5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter session title: ");
                scanf("%s", session_title);
                create_game_session(db, session_title);
                break;
            case 2:
                printf("Enter session ID: ");
                scanf("%d", &session_id);
                printf("Enter your name: ");
                scanf("%s", player_name);
                join_game_session(db, session_id, player_name);
                break;
            case 3:
                display_sessions(db);
                break;
            case 4:
                printf("Enter session ID to display scores: ");
                scanf("%d", &session_id);
                display_scores(db, session_id);
                break;
            case 5:
                printf("Exiting...\n");
                sqlite3_close(db);
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    sqlite3_close(db);
    return 0;
}